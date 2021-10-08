// n x n 정글, 각 격자칸에 토끼 한마리가 있거나 없을 수 있음
// 심바는 최초 몸 크기가 2이고, 1초에 상하좌우 격자칸 이동
// 크기가 큰 토끼 칸은 지나갈 수 없고, 나머지는 모두 지나갈 수 있음
// 크기가 작은 토끼만 잡아먹을 수 있고, 자신의 몸 크기와 같은 마리 수를 잡아먹어야 몸 크기가 1커짐
// 1. 더 이상 먹을 수 있는 토끼가 없으면 종료
// 2. 먹을 수 있는 토끼가 한 마리면, 그 토끼를 먹으러 감
// 3. 먹을 수 있는 토끼가 두 마리 이상이면 거리가 가장 가까운 토끼를 먹으러 감
//    거리는 지나야하는 칸의 최소값이고, 거리가 동일하면 가장 위쪽, 그리고 가장 왼쪽 토끼를 잡아 먹음
// 빈칸은 0, 토끼의 크기는 1~7, 심바는 9를 뜻할 때, 사냥이 종료되는 시간을 출력
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n, res, map[26][26], ch[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

class State {
public:
    int x, y, dis;
    State(int a, int b, int c) {
        this->x = a;
        this->y = b;
        this->dis = c;
    }
    bool operator<(const State &bb) const { // 3번 조건 구현, 우선 순위 큐의 정렬 기준으로 활용
        if (dis == bb.dis) {
            if (x == bb.x) return y > bb.y;
            else return x > bb.x;
        }
        else return dis > bb.dis;
    }
};

class Lion {    // 위치, 현재의 크기와 먹은 마리 수
public:
    int x, y, s, ate;
    void sizeUp() {
        ate = 0;
        s++;
    }
};

int main()
{
    ifstream data;
    data.open("./90_data.txt");
    data >> n;
    priority_queue<State> Q;
    Lion simba;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            data >> map[i][j];
            if (map[i][j] == 9) {
                simba.x = i;
                simba.y = j;
                map[i][j] = 0;
            }
        }
    }
    Q.push(State(simba.x, simba.y, 0));
    simba.s = 2;
    simba.ate = 0;
    while (!Q.empty()) {
        State tmp = Q.top();
        Q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.dis;
        if (map[x][y] != 0 && map[x][y] < simba.s) {
            simba.x = x;
            simba.y = y;
            simba.ate++;
            if (simba.ate >= simba.s) simba.sizeUp();
            map[x][y] = 0;
            for (int i = 1; i <= n; ++i) {  // 한 번 이동할 때마다 방문처리가 갱신됨
                for (int j = 1; j <= n; ++j) {
                    ch[i][j] = 0;
                }
            }
            while (!Q.empty()) Q.pop(); // 큐 초기화
            res = tmp.dis;
        }
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;
            Q.push(State(xx, yy, z + 1));
            ch[xx][yy] = 1;
        }
    }
    cout << res << endl;
    return 0;
}