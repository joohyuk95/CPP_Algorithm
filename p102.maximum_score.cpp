// n개 문제의 점수와 푸는 시간이 각각 주어지면
// m시간 내에 얻을 수 있는 최대 점수 출력
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p102_data.txt");
    int n, m, score, time;
    data >> n >> m;
    vector<int> dp(m+1);    // dp[i] : i시간 내에 얻을 수 있는 최대 점수
    for (int i = 0; i < n; ++i) {
        data >> score >> time;
        for (int j = time; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j-time] + score);
        }
    }
    cout << dp[m] << endl;
    return 0;
}