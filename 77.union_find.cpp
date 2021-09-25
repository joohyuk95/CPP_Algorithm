// union-find(disjoint set) 알고리즘
// 반 학생수(n)와 숫자쌍의 개수(m)이 주어지고, 마지막 줄에 입력되는 숫자쌍이 같은 집합에 속하는지 출력
// (1 <= n <= 1000), (1 <= m <= 3000)
#include <iostream>
#include <fstream>
using namespace std;
int set[1001];

int Find(int x)
{
    if (set[x] == x) return x;
    else return set[x] = Find(set[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a < b) set[b] = a;
    else set[a] = b;
}

int main()
{
    ifstream data;
    data.open("./77_data.txt");
    int n, m, a, b, fa, fb;
    data >> n >> m;
    for (int i = 1; i <= n; ++i) {
        set[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        data >> a >> b;
        Union(a, b);
    }
    data >> a >> b;
    fa = Find(a);
    fb = Find(b);
    if (fa == fb) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}