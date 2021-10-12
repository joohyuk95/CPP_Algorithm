// 한 칸 또는 두 칸씩 돌다리 건너기 Bottop-Up방식
#include <iostream>
using namespace std;

int main()
{
    int n, dp[46];
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n+1; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n+1] << endl;
    return 0;
}