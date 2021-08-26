// n*n 격자판 입력, 격자의 가장자리는 0으로 초기화
// 각 숫자는 높이를 의미, 상하좌우보다 크면 봉우리, 봉우리 개수 구하기
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    int **x = new int *[n+2];
    for (int i = 0; i < n+2; ++i) {
        x[i] = new int[n+2];
        memset(x[i], 0, sizeof(int) * (n+2));
    }
    for (int i = 1; i < n+1; ++i)
        for (int j = 1; j < n+1; ++j)
            cin >> x[i][j];

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (x[i][j] > x[i][j-1] && x[i][j] > x[i][j+1] && x[i][j] > x[i-1][j] && x[i][j] > x[i+1][j])
                ++cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n+2; ++i)
        delete[] x[i];
    delete[] x;
    return 0;
}