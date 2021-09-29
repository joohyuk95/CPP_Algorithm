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
    int n, m, a, b, c;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    for (int i = 1; i <= n; ++i) dist[i] = 2147000000;
    int s, e;
    data >> s >> e;
    dist[s] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < Ed.size(); ++j) {
            int s = Ed[j].s;
            int e = Ed[j].e;
            int w = Ed[j].val;
            if (dist[s] != 2147000000 && dist[s] + w < dist[e]) {
                dist[e] = dist[s] + w;
            }
        }
    }
    for (int i = 0; i < Ed.size(); ++i) {
        int u = Ed[i].s;
        int v = Ed[i].e;
        int w = Ed[i].val;
        if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << dist[e] << endl;
    return 0;
}