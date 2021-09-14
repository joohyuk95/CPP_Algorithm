// 64번 동일문제 (인접리스트 방법)
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int ch[30], cnt, n;
vector<int> map[30];

void DFS(int v)
{
    if (v == n) cnt++;
    else {
        for (int i = 0; i < map[v].size(); ++i) {
            if (ch[map[v][i]] == 0) {
                ch[map[v][i]] = 1;
                DFS(map[v][i]);
                ch[map[v][i]] = 0;
            }
        }
    }
}

int main()
{
    ifstream data;
    data.open("./64_data.txt");
    int m, a, b;
    data >> n >> m;
    for (int i = 1; i <= m; ++i) {
        data >> a >> b;
        map[a].push_back(b);
    }
    ch[1] = 1;
    DFS(1);
    cout << cnt << endl;
    return 0;
}