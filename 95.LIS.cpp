// 최장 증가 부분수열
// 최대 길이 출력
#include <iostream>
#include <fstream>
using namespace std;
int n, res, arr[1001], dp[1001]; // dp[i] : i번째 인덱스의 수로 '끝나는' 수열의 LIS

int main()
{
    ifstream data;
    data.open("./95_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i) data >> arr[i];
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int max = 0;
        for (int j = i-1; j >= 1; --j) {
            if (arr[i] > arr[j] && dp[j] > max) max = dp[j];
        }
        dp[i] = ++max;
        if (dp[i] > res) res = dp[i];
    }
    cout << res << endl;
    return 0;
}