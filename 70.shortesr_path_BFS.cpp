// 방향 그래프가 주어지면 1번 정점에서 각 정점으로 가는 최단거리 차례대로 출력
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int ch[30], dis[30];
vector<int> map[30];
queue<int> Q;

int main()
{
    ifstream data;
    data.open("./70_data.txt");
    int n, m, a, b, x;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b;
        map[a].push_back(b);
    }
    Q.push(1);
    ch[1] = 1;
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();    // 가장 앞에있는 원소 삭제
        for (int i = 0; i < map[x].size(); ++i) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1;    // 이전 정점까지의 거리 + 1
            }
        }
    }
    for (int i = 2; i <= n; ++i)
        cout << i << " : " << dis[i] << endl;
    return 0;
}