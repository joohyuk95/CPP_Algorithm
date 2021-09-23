#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Data {
public:
    int money;
    int when;
    
    Data(int a, int b)  // 생성자
    {
        this->money = a;
        this->when = b;
    }
    
    bool operator<(const Data &b) const // 연산자 오버로딩
    {
        return this->when > b.when; // 기간을 기준으로 내림차순 정렬, sort 함수 사용하기 위한 작업
    }
};

int main()
{
    ifstream data;
    data.open("./75_data.txt");
    int n, i, j, a, b, res = 0, max = -2147000000;
    vector<Data> T;
    priority_queue<int> pQ;
    data >> n;
    for (i = 1; i <= n; ++i) {
        data >> a >> b;
        T.push_back(Data(a,b));
        if (b > max) 
            max = b;
    }
    sort(T.begin(), T.end());
    j = 0;
    for (i = max; i >= 1; --i) {  // 기간 3일짜리 중에 젤 비싼거 + 2일짜리 중에 + --- + 1일짜리 중에
        for ( ; j < n; ++j) {
            if (T[j].when < i) break;
            pQ.push(T[j].money);
        }
        if (!pQ.empty()) {
            res += pQ.top();
            pQ.pop();
        }
    }
    cout << res << endl;
    return 0;
}