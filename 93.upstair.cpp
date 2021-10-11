// 계단오르기 (momoization)
// 한 번에 한 계단 또는 두 계단씩 오를 수 있음
#include <iostream>
using namespace std;
int n, dp[46];

int DFS(int n)
{
    if (dp[n]) return dp[n];
    if (n == 1 || n == 2) return n;
    return dp[n] = DFS(n-1) + DFS(n-2);
}

int main()
{
    cin >> n;
    cout << DFS(n) << endl;
    return 0;
}