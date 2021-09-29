// digraph와 간선의 가중치가 주어지면
// 출발점에서 도착점까지의 최소비용 출력, 음의 사이클이 존재하면 -1 출력
// 벨만-포드 알고리즘은 '음의 사이클'이 존재하면 안 된다. (음의 가중치는 가능)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int dist[101];

class Edge {
public:
    int s;
    int e;
    int val;

    Edge (int a, int b, int c) {
        this->s = a;
        this->e = b;
        this->val = c;
    }
};

int main()
{
    ifstream data;
    data.open("./81_data.txt");
    vector<Edge> Ed;
    int n, m, a, b, c, start, end;
    bool flag = false;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    data >> start >> end;
    
    for (int i = 1; i <= n; ++i) dist[i] = 2147000000;
    dist[start] = 0;
    for (int i = 1; i <= n-1; ++i) {    // n-1번 반복
        for (int j = 1; j <= n; ++j) {
            if (dist[j] != 2147000000) {
                for (int k = 0; k < m; ++k) {
                    if (Ed[k].s == j && dist[Ed[k].e] > dist[j] + Ed[k].val) {
                        dist[Ed[k].e] = dist[j] + Ed[k].val;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != 2147000000) {
            for (int j = 0; j < m; ++j) {
                if (Ed[j].s == i && dist[Ed[j].e] > dist[i] + Ed[j].val) {
                    flag = true;
                }
            }
        }
    }
    if (flag) cout << -1 << endl;
    else cout << dist[end] << endl;
    return 0;
}