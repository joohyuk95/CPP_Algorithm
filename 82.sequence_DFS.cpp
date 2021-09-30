// 서로 다른 n개의 자연수 중 r개를 뽑아 일렬로 나열하는 경우의 수를 오름차순으로 출력, 마지막 줄에는 총 개수 출력
#include <iostream>
using namespace std;
int n, r, cnt;
int a[20], res[20], ch[20];

void DFS(int L)
{
    if (L == r + 1) {
        for (int j = 1; j <= r; ++j)
            cout << res[j] << ' ';
        cnt++;
        cout << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (ch[i] == 0) {
                res[L] = a[i];
                ch[i] = 1;
                DFS(L + 1);
                ch[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    DFS(1);
    cout << cnt << endl;
    return 0;
}