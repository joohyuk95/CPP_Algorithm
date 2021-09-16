// 67번 동일문제 (인접리스트 활용)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, ch[30], cost = 2147000000;
vector<pair<int, int>> map[30]; // first는 연결된 정점, second는 가중치

void DFS(int v, int sum)
{
    if (v == n) {
        if (sum < cost) cost = sum;
    } else {
        for (int i = 0; i < map[v].size(); ++i) {
            if (ch[map[v][i].first] == 0) {
                ch[map[v][i].first] = 1;
                DFS(map[v][i].first, sum + map[v][i].second);
                ch[map[v][i].first] = 0;
            }
        }
    }
}

int main()
{
    ifstream data;
    data.open("./67_data.txt");
    int m, a, b, c;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    ch[1] = 1;
    DFS(1, 0);
    cout << cost << endl;
    return 0;
}