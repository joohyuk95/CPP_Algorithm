// n종류의 보석과 m kg의 무게를 담을 수 있는 가방이 있다.
// 각 보석의 무게와 가치가 주어질 때
// 가방에 담을 수 있는 보석의 최대가치를 출력
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p100_data.txt");
    int n, m, w, v;
    data >> n >> m;
    vector<int> dp(m+1);    // dp[i] : 무게 제한이 i인 가방에 담을 수 있는 최대가치
    for (int i = 0; i < n; ++i) {
        data >> w >> v;
        for (int j = w; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j-w] + v); // 기존의 최대가치와, 지금 넣을 보석으로 최대무게를 맞췄을 때의 최대가치 중 큰 거
        }
    }
    cout << dp[m] << endl;
    return 0;
}