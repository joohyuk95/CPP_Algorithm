// 이진트리 넓이우선탐색(BFS)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int Q[100], front = -1, back = -1, ch[10]; // Queue 활용
vector<int> map[10];    // 인접리스트 활용

int main()
{
    ifstream data;
    data.open("./69_data.txt");
    int a, b, x;
    for (int i = 1; i <= 6; ++i) {
        data >> a >> b;
        map[a].push_back(b);  // 방향그래프가 아니므로 연결관계 다 넣어줌
        map[b].push_back(a);
    }
    Q[++back] = 1;
    ch[1] = 1;
    while (front < back) { // Queue에 원소가 없을 때까지
        x = Q[++front]; // Queue 원소 추출
        cout << x << ' ';
        for (int i = 0; i < map[x].size(); ++i) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;  // 방문처리
                Q[++back] = map[x][i]; // Queue에 원소 추가
            }
        }
    }
    cout << endl;
    return 0;
}