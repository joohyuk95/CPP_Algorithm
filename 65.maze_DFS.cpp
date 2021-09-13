// 7x7 격자 미로 탈출 경로의 가지 수를 출력
// (1,1)에서 출발해서 (7,7) 도착, 1은 벽, 0이 통로, 상하좌우로만 움직임
#include <iostream>
#include <fstream>
using namespace std;
int cnt, maze[8][8], ch[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int row, int col)
{
    int row_next, col_next;
    if (row == 7 && col == 7) ++cnt;
    else {
        for (int i = 0; i < 4; ++i) {
            row_next = row + dx[i];
            col_next = col + dy[i];
            if (row_next < 1 || row_next > 7 || col_next < 1 || col_next > 7)
                continue;
            if (maze[row_next][col_next] == 0 && ch[row_next][col_next] == 0) {
                ch[row_next][col_next] = 1;
                DFS(row_next, col_next);
                ch[row_next][col_next] = 0;
            }
        }
    }
}

int main()
{
    ifstream data;
    data.open("./65_data.txt");
    for (int i = 1; i <= 7; ++i)
        for (int j = 1; j <= 7; ++j)
            data >> maze[i][j];
    ch[1][1] = 1;
    DFS(1, 1);
    cout << cnt << endl;
    return 0;
}