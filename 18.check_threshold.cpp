// 자연수 개수와 임계값을 입력받아 최대 연속으로 임계값을 넘는 개수 구하기 

#include <iostream>
using namespace std;

int main()
{
    int n, m, data[100], cnt = 0, max = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        if (data[i] > m) {
            ++cnt;
            if (cnt > max)
                max = cnt;
        } else {
            cnt = 0;
        }
    }
    cout << max << endl;
    return 0;
}