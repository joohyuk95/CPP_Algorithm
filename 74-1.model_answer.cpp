// 자연수가 입력되는 것을 활용하여 부호를 음수로 변환하여 우선순위 큐 활용
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    ifstream data;
    data.open("./73_data.txt");
    int a;
    priority_queue<int> pQ;
    while (true) {
        data >> a;
        if (a == -1) break;
        if (a == 0) {
            if (pQ.empty()) cout << -1 << endl;
            else {
                cout << -pQ.top() << endl;
                pQ.pop();
            }
        }
        else pQ.push(-a);
    }
    return 0;
}