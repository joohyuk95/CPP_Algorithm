// n개의 자연수 배열과 1부터 n까지 오름차순 배열을 같은 숫자끼리 연결할 때, 겹치지 않는 최대 선의 개수
// LIS(Longest Increasing Subsequence)와 동일문제
#include <iostream>
#include <fstream>
using namespace std;
int n, res, arr[101], dp[101];

int main()
{
    ifstream data;
    data.open("./96_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i) data >> arr[i];
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int max = 0;
        for (int j = i; j >= 1; --j) {
            if (arr[i] > arr[j] && dp[j] > max) max = dp[j];
        }
        dp[i] = ++max;
        if (dp[i] > res) res = dp[i];
    }
    cout << res << endl;
    return 0;
}