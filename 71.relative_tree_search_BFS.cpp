// 현재 위치와 목표 위치의 1차원 좌표가 주어지면 목표점까지 점프의 최소 횟수 구하기
// 점프는 앞으로 1, 뒤로 1, 앞으로 5 의 경우의 수가 있음, 좌표 범위 [1, 10000]
#include <iostream>
#include <queue>
using namespace std;
int ch[10001], d[3] = {1, -1, 5};

int main()
{
    int s, e, pos, x;
    cin >> s >> e;
    queue<int> Q;
    ch[s] = 1;  // 점프 횟수로 방문처리
    Q.push(s);
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        for (int i = 0; i < 3; ++i) {
            pos = x + d[i];
            if (pos <= 0 || pos > 10000) continue;
            if (pos == e) {
                cout << ch[x] << endl;
                exit(0);
            }
            if (ch[pos] == 0) {  // 각각의 점프 경우의 수 결과로, 동일한 좌표를 경유하지 않도록 한다
                ch[pos] = ch[x] + 1;
                Q.push(pos);
            }
        }
    }
    return 0;
}
