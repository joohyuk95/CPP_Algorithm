// 다익스트라 알고리즘
// 1번 정점에서 모든 정점으로의 최소 비용 출력
#include <iostream>
#include <fstream>
#include <vector>
#define x first
#define y second
using namespace std;
int ch[30], dist[30];
vector<pair<int,int>> map[30];

int main()
{
    ifstream data;
    data.open("./80_data.txt");
    int n, m, a, b, c, min;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    for (int i = 0; i <= n; ++i) dist[i] = 2147000000;  // 모든 정점과의 거리를 무한대로 초기화
    dist[1] = 0; // 1에서 시작하므로 1의 비용을 0으로 부여
    for (int i = 1; i <= n; ++i) { // n개의 정점이 존재하므로, 모든 정점을 다 들러야 종료됨
        min = 0;    // dist[0] = inf 로 초기화 되어 있으므로, 방문 안한 정점 중 최소거리인 정점을 찾기 위해 최초 조건으로 dist[0]을 활용
        for (int j = 1; j <= n; ++j) {  // 1부터 n까지
            if (ch[j] == 0 && dist[j] < dist[min]) // 방문처리 안됐고, 거리가 최소보다 작으면 현재 최소거리인 정정을 수정
                min = j;
        }
        ch[min] = 1;  // 방문처리
        for (int j = 0; j < map[min].size(); ++j) {  // 인접리스트의 열
            int v = map[min][j].x;
            int cost = map[min][j].y;
            if (dist[v] > dist[min] + cost) {  // 업데이트
                dist[v] = dist[min] + cost;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else cout << i << " : impossible" << endl;
    }
    return 0;
}