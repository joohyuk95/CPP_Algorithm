// inversion sequence : 1부터 n까지 수를 한 번씩만 사용한 수열에서
// 각각의 수 앞에 놓여 있는 자신보다 큰 수들의 개수의 수열
// inversion sequence가 주어졌을 때, 원래 수열 구하기
#include <iostream>
using namespace std;

int main()
{
    int n, cnt;
    cin >> n;
    int *inv = new int[n];
    int *origin = new int[n]();
    for (int i = 0; i < n; ++i)
        cin >> inv[i];

    for (int i = 0; i < n; ++i) {
        cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (origin[j] == 0) {
                ++cnt;
                if (cnt == inv[i] + 1) {
                    origin[j] = i + 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << origin[i] << ' ';
    return 0;
}