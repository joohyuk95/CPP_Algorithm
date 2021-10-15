// n x n 격자 정보가 주어지면 (1, 1)에서 (n, n)으로 가능 최소비용 출력
// 오른쪽 또는 아래로만 이동 가능
// Bottom-up 방식
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int map[21][21], dp[21][21];

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./98_data.txt");
    int n;
    data >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) data >> map[i][j];
    dp[1][1] = map[1][1];
    for (int i = 2; i <= n; ++i) {
        dp[1][i] = dp[1][i-1] + map[1][i];
        dp[i][1] = dp[i-1][1] + map[i][1];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + map[i][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}