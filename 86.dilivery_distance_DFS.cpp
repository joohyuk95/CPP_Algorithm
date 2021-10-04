// n x n 격자 지도가 주어짐, 0은 빈칸, 1은 집, 2는 피자집을 의미
// 배달거리는 |x1-x2| + |y1-y2|, 배달거리가 최소인 m개의 피자집을 선택
// 각 피자집의 도시 배달거리는 모든 집까지의 배달거리를 합한 값
// 도시의 최소 피자배달거리를 출력
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<pair<int, int> > pizza;
vector<pair<int, int> > house;
int ch[20], n, m, dis, sum, res = 2147000000;

void DFS(int L, int s)
{
    if (L == m) {
        sum = 0;
        for (int i = 0; i < house.size(); ++i) { // 모든 집들에 대해서
            int x1 = house[i].first;
            int y1 = house[i].second;
            dis = 2147000000;
            for (int j = 0; j < m; ++j) {   // 각 집의 가장 가까운 피자집과의 거리 dist
                int x2 = pizza[ch[j]].first;
                int y2 = pizza[ch[j]].second;
                dis = min(dis, abs(x1-x2) + abs(y1-y2));
            }
            sum += dis;
        }
        if (sum < res) res = sum;
    } else {
        for (int i = s; i < pizza.size(); ++i) {
            ch[L] = i;
            DFS(L + 1, i + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // iostream, stdio 서로 독립된 버퍼 사용, 실행속도 향상
    ifstream data;
    data.open("./86_data.txt");
    int n, a;
    data >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            data >> a;
            if (a == 1) house.push_back(make_pair(i , j));  // 집들의 좌표 저장
            else if (a == 2) pizza.push_back(make_pair(i, j)); // 피자집들의 좌표 저장
        }
    }
    DFS(0, 0);
    cout << res << endl;
    return 0;
}