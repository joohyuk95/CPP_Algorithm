// 플로이드-워샬 알고리즘 응용 (모든 노드에서 모든 노드로의 최소 비용)
// 모든 회원과 친구 : 1점, 모든 회원이 친구 or 친구의 친구 : 2, 모든 회원이 친 or 친친 or 친친친 : 3
// 같은 방식으로 이상의 점수도 정해진다. 친구거나 친구의 친구이기도 하면 친구사이로 본다.
// n명의 회원들 간의 친구 관계가 모두 주어지면, 첫 째 줄에 회장후보 수와 회장후보 점수를 출력, 둘 째 줄에 회장후보의 번호를 모두 출력
// 점수가 가장 작은 회원이 회장후보이며, 입력 마지막에 -1이 두 번 입력됨
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p104_data.txt");
    int n, a, b, score = 100, cnt = 0;
    data >> n;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 100));
    vector<int> res(n+1);
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    
    while (true) {
        data >> a >> b;
        if (a == -1 && b == -1) break;
        dp[a][b] = 1;
        dp[b][a] = 1;
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
            res[i] = max(res[i], dp[i][j]);
        }
        score = min(score, res[i]);
    }
    for (int i = 1; i <= n; ++i) { 
        if (res[i] == score) cnt++;
    }
    cout << score << ' ' << cnt << endl;
    
    for (int i = 1; i <= n; ++i) {
        if (res[i] == score) cout << i << ' ';
    }
    cout << endl;
    return 0;
}