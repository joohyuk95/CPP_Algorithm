// 7x7 격자 미로 탈출하는 최단경로의 거리 출력
// (1,1) 출발, (7,7) 도착, 상하좌우로 이동하며, 거리는 움직인 횟수
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int map[8][8], dist[8][8];
int dx[4] = {-1, 0 , 1, 0};
int dy[4] = {0, 1, 0, -1};

class Loc {
public:
    int x;
    int y;
    Loc(int a, int b) {
        this->x = a;
        this->y = b;
    }
};

int main()
{
    ifstream data;
    data.open("./88_data.txt");
    queue<Loc> Q;
    for (int i = 1; i <= 7; ++i) for (int j = 1; j <= 7; ++j) data >> map[i][j];
    Q.push(Loc(1, 1));
    map[1][1] = 1;
    while (!Q.empty()) {
        Loc tmp = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = tmp.x + dx[i];
            int yy = tmp.y + dy[i];
            if (map[xx][yy] == 0 && xx >= 1 && xx <= 7 && yy >= 1 && yy <= 7) {
                Q.push(Loc(xx, yy));
                map[xx][yy] = 1;
                dist[xx][yy] = dist[tmp.x][tmp.y] + 1;
            }
        }
    }
    if (dist[7][7] == 0) cout << -1 << endl;    // 도착할 수 없음
    else cout << dist[7][7] << endl;
    return 0;
}