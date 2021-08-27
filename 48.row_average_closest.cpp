// 9 x 9 격자판, 각 행의 평균과 평균과 가장 가까운 값 출력
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream data;
    data.open("48_data.txt");

    int n = 9, sum, tmp, diff;
    int **row = new int *[n];
    for (int i = 0; i < n; ++i)
        row[i] = new int[n+1];
    
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j <= n; ++j) {
            if (j == n)
                row[i][j] = round((1.0) * sum / n);
            else {
                data >> row[i][j];
                sum += row[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        tmp = 100;
        for (int j = 0; j < n; ++j) {
            diff = abs(row[i][n] - row[i][j]); 
            if (diff < abs(row[i][n] - tmp))
                tmp = row[i][j];
        }
        cout << row[i][n] << ' ' << tmp <<endl;
    }
    for (int i = 0; i < n; ++i)
        delete[] row[i];
    delete[] row;
    return 0;
}