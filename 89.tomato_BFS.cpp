// nxm 상자에 토마토가 보관되어 있음, 익었으면 1, 그렇지 않으면 0, 없으면 -1
// 익은 토마토는 하루가 지나면 상하좌우에 있는 덜 익은 토마토를 익게함.
// 저절로 익는 경우는 없다고 가정했을 때, 토마토가 모두 익을 때까지의 최소 날짜를 출력
// 처음부터 모든 토마토가 익어있으면 0, 모두 익을 수 없으면 -1을 출력.
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int m, n, tom[1001][1001], res = -2147000000, dis[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool flag = true;

class Loc {
public:
    int x, y;
    Loc(int a, int b) {
        this->x = a;
        this->y = b;
    }
};
queue<Loc> Q;

int main()
{
    ifstream data;
    data.open("./89_data.txt");
    data >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            data >> tom[i][j];
            if (tom[i][j] == 1) Q.push(Loc(i, j));
            if (tom[i][j] == 0) flag = false;
        }
    }
    if (flag) {
        cout << 0 << endl;
        exit(0);
    }
    while (!Q.empty()) {
        Loc tmp = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = tmp.x + dx[i];
            int yy = tmp.y + dy[i];
            if (tom[xx][yy] == 0 && xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                Q.push(Loc(xx, yy));
                tom[xx][yy] = 1;
                dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
            }
        }
    }
    flag = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tom[i][j] == 0) flag = false;
        }
    }
    if (flag) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (res < dis[i][j]) res = dis[i][j];
            }
        }
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}