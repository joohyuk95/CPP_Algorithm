// 자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합 모두 출력.
// 공집합은 출력하지 않음.
#include <iostream>
using namespace std;
int n, ch[100];

void DFS(int L)
{
    if (L == n + 1) {
        for (int i = 1; i <= n; ++i) {
            if (ch[i] == 1) cout << i << ' ';
        }
        cout << endl;
    } else {        // 부분집합은 상위집합의 원소를 포함되는지 안 되는지에 따라 2^n 개가 존재.
        ch[L] = 1;  // ch[L] = 1 : 원소 L이 포함됨을 의미
        DFS(L + 1); // 재귀함수가 호출되는 시점에 따라, 같은 메모리 공간에 다른 값이 존재할 수 있음
        ch[L] = 0;  // 원소 L이 포함되지 않음
        DFS(L + 1);
    }
}

int main()
{
    cin >> n;
    DFS(1);
    return 0;
}