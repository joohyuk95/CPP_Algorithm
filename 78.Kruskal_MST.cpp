#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[10001];

class Edge {
public:
    int s;
    int e;
    int val;

    Edge(int a, int b, int c)
    {
        this->s = a;
        this->e = b;
        this->val = c;
    }
    bool operator<(const Edge &b) const
    {
        return this->val < b.val;
    }
};

int Find(int v)
{
    if (v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b) unf[a] = b;
}

int main()
{
    ifstream data;
    data.open("./78_data.txt");
    vector<Edge> Ed;
    int n, m, a, b, c, cnt = 0, res = 0;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        unf[i] = i;
        data >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    sort(Ed.begin(), Ed.end());
    for (int i = 0; i < m; ++i) {
        int fa = Find(Ed[i].s);
        int fb = Find(Ed[i].e);
        if (fa != fb) {
            res += Ed[i].val;
            Union(Ed[i].s, Ed[i].e);
        }
    }
    cout << res << endl;
    return 0;
}