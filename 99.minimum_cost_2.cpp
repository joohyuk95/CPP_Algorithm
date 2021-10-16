// 98번 동일문제 (Top-Down 방식)
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n, map[21][21], dp[21][21];

int DFS(int row, int col)
{
    if (dp[row][col]) return dp[row][col];
    if (row == 1 && col == 1) return map[row][col];
    else if (row == 1) return dp[row][col] = DFS(row, col-1) + map[row][col];
    else if (col == 1) return dp[row][col] = DFS(row-1, col) + map[row][col];
    return dp[row][col] = min(DFS(row-1, col), DFS(row, col-1)) + map[row][col];
}

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./98_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) data >> map[i][j];
    cout << DFS(n, n) << endl;
    return 0;
}