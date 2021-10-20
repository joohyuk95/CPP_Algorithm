// n개의 vertex와 m개의 edge로 가중치 방향그래프가 주어지면
// 모든 vertex에서 모든 vertex로의 최소 비용을 행렬로 출력
// 자기자신으로 가는 비용은 0, 갈 수 없으면 'M'을 출력한다.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p103_data.txt");
    int n, m, a, b, c;
    data >> n >> m;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 2000));
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b >> c;
        dp[a][b] = c;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == 2000) cout << "M ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}