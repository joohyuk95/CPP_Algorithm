// n+1일에 휴가, 상담하는데 걸리는 날수 n과 금액 T가 매일마다 주어졌을 때 최대 이익을 출력
#include <iostream>
#include <fstream>
using namespace std;
int n, T[20], P[20], res = 0;

void DFS(int L, int sum)
{
    if (L == n + 1) {
        if (sum > res) res = sum;
    } else {
        if (L + T[L] <= n + 1) DFS(L + T[L], sum + P[L]);
        DFS(L + 1, sum);
    }
}

int main()
{
    ifstream data;
    data.open("./84_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i)
        data >> T[i] >> P[i];
    DFS(1, 0);
    cout << res << endl;
    return 0;
}