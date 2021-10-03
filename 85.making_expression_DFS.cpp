// n 개의 수열과 사칙연산이 개수로 주어졌을 때 만들 수 있는 수식
// 맨 앞쪽 연산자부터 차례로 계산한 결과 중 최댓값과 최솟값 출력
// 연산자 총 개수는 n-1개
#include <iostream>
using namespace std;
int n, seq[10], op[5], maxi = -2147000000, mini = 2147000000;

void DFS(int L, int res)
{
    if (L == n) {
        if (res > maxi) maxi = res;
        if (res < mini) mini = res;
    } else {
        if (op[0] > 0) {
            op[0]--;
            DFS(L + 1, res + seq[L]);
            op[0]++;
        }
        if (op[1] > 0) {
            op[1]--;
            DFS(L + 1, res - seq[L]);
            op[1]++;
        }
        if (op[2] > 0) {
            op[2]--;
            DFS(L + 1, res * seq[L]);
            op[2]++;
        }
        if (op[3] > 0) {
            op[3]--;
            DFS(L + 1, res / seq[L]);
            op[3]++;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> seq[i];
    for (int i = 0; i < 4; ++i)
        cin >> op[i];
    DFS(1, seq[0]);
    cout << maxi << endl << mini << endl;
    return 0;
}