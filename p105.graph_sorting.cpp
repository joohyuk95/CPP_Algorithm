// 위상정렬 (digraph에서 모든 노드의 작업 순서 결정)
// 전체 일의 순서를 출력
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./p105_data.txt");
    int n, m, a, b;
    data >> n >> m;
    vector<vector<int> > graph(n+1, vector<int> (n+1));
    vector<int> degree(n+1);
    queue<int> Q;
    for (int i = 0; i < m; ++i) {
        data >> a >> b;
        graph[a][b] = 1;
        degree[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 0) Q.push(i);  // 진입 차수가 0인 시작 지점 후보를 큐에 삽입
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        cout << now << ' ';
        for (int i = 1; i <= n; ++i) {
            if (graph[now][i] == 1) {   // pop된 노드의 간선 모두 제거
                degree[i]--;
                if (degree[i] == 0) Q.push(i); // 간선 제거 후에 연결 돼있던 노드의 진입 차수가 0이면 큐에 삽입
            }
        }
    }
    return 0;
}