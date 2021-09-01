#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int a[701][701], dy[701][701];

int main()
{
    ifstream data;
    data.open("50_data.txt");
    int h, w, n, m, i, j, tmp, max = -2147000000;
    cin >> h >> w;
    for (i = 1; i <= h; ++i) {
        for (j = 1; j <= w; ++j) {
            data >> a[i][j];
            dy[i][j] = dy[i-1][j] + dy[i][j-1] - dy[i-1][j-1] + a[i][j];
        }
    }
    cin >> n >> m;
    for (i = n; i <= h; ++i) {
        for (j = m; j <= w; ++j) {
            tmp = dy[i][j] - dy[i-n][j] - dy[i][j-m] + dy[i-n][j-m];
            if (tmp > max) max = tmp;
        }
    }
    cout << max << endl;
    return 0;
}