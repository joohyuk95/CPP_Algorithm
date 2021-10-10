// 91 동일 문제, Top-Down 방식 : 재귀, 메모이제이션
#include <iostream>
using namespace std;
int n, dp[50];

int DFS(int n)
{
    if (dp[n]) return dp[n];
    if (n == 1 || n == 2) return n;
    else return dp[n] = DFS(n-1) + DFS(n-2);
}

int main()
{
    cin >> n;
    cout << DFS(n) << endl;
    return 0;
}