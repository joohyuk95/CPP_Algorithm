// 정면, 오른쪽 측면 단면의 높이 정보를 토대로 블록의 최대개수 출력
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, sum = 0;
    cin >> n;
    int **block = new int *[n];
    for (int i = 0; i < n; ++i)
        block[i] = new int [n];
    
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < n; ++j)
            block[j][i] = tmp;
    }
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < n; ++j) {
            if (block[i][j] > tmp)
                block[i][j] = tmp;
            sum += block[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}