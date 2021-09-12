// digraph가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력
#include <iostream>
#include <fstream>
using namespace std;
int n, matrix[21][21], ch[30], cnt;

void DFS(int x)
{
    if (x == n) ++cnt;
    else {
        for (int i = 1; i <= n; ++i) {
            if (matrix[x][i] == 1 && ch[i] == 0) {
                ch[i] = 1;  // 해당 정점 방문처리
                DFS(i);
                ch[i] = 0;  // 상위트리로 되돌아가면서 방문해제
            }
        }
    }
}

int main()
{
    ifstream data;
    data.open("./64_data.txt");
    int m, start, end;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> start >> end;
        matrix[start][end] = 1;
    }
    ch[1] = 1;
    DFS(1);
    cout << cnt << endl;
    return 0;
}