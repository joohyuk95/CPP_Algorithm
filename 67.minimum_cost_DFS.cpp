// 가중치 방향그래프 주어지면 1번에서 N번 정점으로가는 최소비용 출력
#include <iostream>
#include <fstream>
using namespace std;
int n, minimum = 2147000000, total, matrix[21][21], ch[30];

void DFS(int x)
{
    if (x == n) {
        if (minimum > total) minimum = total;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (matrix[x][i] > 0 && ch[i] == 0) {
                ch[i] = 1;
                total += matrix[x][i];
                DFS(i);
                ch[i] = 0;
                total -= matrix[x][i];
            }
        }
    }
}

int main()
{
    ifstream data;
    data.open("./67_data.txt");
    int m, start, end, cost;
    data >> n >> m;
    for (int i = 0; i < m; ++i) {
        data >> start >> end >> cost;
        matrix[start][end] = cost;
    }
    ch[1] = 1;
    DFS(1);
    cout << minimum << endl;
    return 0;
}