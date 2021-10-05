// 격자판 정보가 주어지면 섬의 개수를 출력. (1은 섬, 0은 바다)
// 섬은 1이 상하좌우, 대각선으로 연결되어 있다.
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
int map[21][21], n, cnt;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 대각선 포함
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // (1, 1)에서 시작하므로 이 순서가 효율적
queue<pair<int, int> > Q;

int main()
{
    ifstream data;
    data.open("./87_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) data >> map[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1) {
                Q.push(make_pair(i, j)); // 발견된 섬의 일부분
                map[i][j] = 0;
                while (!Q.empty()) { // 발견된 섬의 일부분으로부터 연결된 모든 지형을 탐색
                    int x = Q.front().first, y = Q.front().second;
                    Q.pop();
                    for (int k = 0; k < 8; ++k) {
                        int xx = x + dx[k], yy = y + dy[k];
                        if (map[xx][yy] == 1) {
                            Q.push(make_pair(xx, yy));
                            map[xx][yy] = 0;
                        }
                    }
                }
                cnt++; // 섬 한 개 탐색 완료
            }
        }
    }
    cout << cnt << endl;
    return 0;
}