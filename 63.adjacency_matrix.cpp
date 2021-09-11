// vertice의 개수 N과 edge의 개수 M이 주어지며
// M개의 연결정보와 length가 입력됨, 인접행렬 출력
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream data;
    data.open("63_data.txt");
    int n, m, start, end, length;
    data >> n >> m;
    int **matrix = new int *[n + 1];
    for (int i = 1; i <= n; ++i)
        matrix[i] = new int [n + 1]();
    for (int i = 1; i <= m; ++i) {
        data >> start >> end >> length;
        matrix[start][end] = length;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 1; i <= n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}