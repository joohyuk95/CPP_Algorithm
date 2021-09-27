// 정점과 간선의 개수를 입력하고, 간선의 수만큼 연결 정보를 입력한다(가중치 포함)
// 모든 정점을 연결하면서 최소가 되는 가중치를 출력 (우선순위 큐 활용)
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int ch[30];

class Edge {
public:
    int e;
    int val;
    
    Edge(int a, int b)
    {
        this->e = a;
        this->val = b;
    }

    bool operator<(const Edge &rhs) const
    {
        return this->val > rhs.val; // 정렬 기준은 멤버 변수 val, 정렬 방식은 오름차순, 우선순위 큐 정렬시 활용됨
    }
};

int main()
{
    ifstream data;
    data.open("./78_data.txt");
    priority_queue<Edge> pq;
    vector<pair<int, int>> map[30];
    int m, n, a, b, c, res = 0;
    data >> m >> n;
    for (int i = 1; i <= n; ++i) {
        data >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));  // 무방향 그래프
    }
    pq.push(Edge(1, 0));  // 1번 정점에서 시작
    while (!pq.empty()) {
        Edge tmp = pq.top();  // queue에 담긴 것들 중, 가중치가 가장 작은거부터 확장
        pq.pop();
        int v = tmp.e;
        int cost = tmp.val;
        if (ch[v] == 0) {   // 연결 안된 것만 연결
            res += cost;
            ch[v] = 1;  // 중복합 제거
            for (int i = 0; i < map[v].size(); ++i) {
                if (ch[map[v][i].first] == 0) { // ch[정점 v와 연결된 i번째 요소 정점] = 0 이면
                    pq.push(Edge(map[v][i].first, map[v][i].second));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}