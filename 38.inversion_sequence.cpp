// inversion sequence : 1부터 n까지 수를 한 번씩만 사용한 수열에서
// 각각의 수 앞에 놓여 있는 자신보다 큰 수들의 개수의 수열
// inversion sequence가 주어졌을 때, 원래 수열 구하기
#include <iostream>
using namespace std;

int main()
{
    int n, cnt, add;
    cin >> n;
    int *inv = new int[n];
    int *origin = new int[n]();
    for (int i = 0; i < n; ++i)
        cin >> inv[i];

    for (int i = 0; i < n; ++i) {
        cnt = 0;
        add = 0;
        for (int j = i-1; j >= 0; --j) {
            if (inv[i] >= inv[j])
                ++cnt;
        }
        while (origin[inv[i] + cnt + add] != 0)
            ++add;
        origin[inv[i] + cnt + add] = i + 1;
    }
    for (int i = 0; i < n; ++i)
        cout << origin[i] << ' ';
    return 0;
}