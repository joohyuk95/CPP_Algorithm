// 길이 n인 선을 길이 1, 2로 자르는 방법의 수 구하기
// 왼쪽을 기준으로 자르는 위치가 다르면 다른 경우로 생각
// Bottom-Up 방식
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, dp[46];
    cin >> n;

    dp[1] = 1;  // 1m 인 선을 자르는 가지수
    dp[2] = 2;  // 2m 인 선을 자르는 가지수

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[n] << endl;
    return 0;
}