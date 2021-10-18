// n종류인 각 동전의 가치와, 거스름 돈 m이 주어지면
// 거슬러 줄 동전의 최소개수를 출력 (각 동전은 무한정 쓸 수 있다.)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p101_data.txt");
    int n, m;
    data >> n;
    vector<int> coin(n);
    for (int i = 0; i < n; ++i) data >> coin[i];
    data >> m;
    vector<int> dp(m+1, 500);   // dp[i] : i원 거슬러줄 때 동전의 최소개수
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = coin[i]; j <= m; ++j) {
            dp[j] = min(dp[j], dp[j-coin[i]] + 1);
        }
    }
    cout << dp[m] << endl;
    return 0;
}