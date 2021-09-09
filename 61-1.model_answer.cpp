// N개의 원소로 구성된 자연수 집합으로 +, - 연산으로 특정수 M을 만들 수 있는 가지 수를 출력
// 없으면 -1 을 출력하고, 각 원소는 최대 한번만 사용가능
#include <iostream>
using namespace std;
int n, m, cnt, a[11];

void DFS(int L, int sum)
{
    if (L == n + 1) {
        if (sum == m) {
            cnt++;
        }
    } else {
        DFS(L + 1, sum + a[L]);
        DFS(L + 1, sum);
        DFS(L + 1, sum - a[L]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    DFS(1, 0);
    if (cnt == 0) cout << -1 << endl;
    else cout << cnt << endl;
    return 0;
}