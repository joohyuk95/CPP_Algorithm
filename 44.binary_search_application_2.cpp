// n개의 마구간에 c마리의 말을 한 마리씩 배치
// 가장 가까운 거리가 최대가 되도록 배치, 최댓값 출력
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int Count(int len, int x[])
{
    int cnt = 1, pos = x[0];
    for (int i = 1; i < n; ++i) {
        if (x[i] - pos >= len) {
            ++cnt;
            pos = x[i];
        }
    }
    return cnt;
}

int main()
{
    int c, lt = 1, rt, mid, res;
    cin >> n >> c;
    int *x = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x + n);
    rt = x[n];
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        if (Count(mid, x) >= c) {
            res = mid;
            lt = mid + 1;
        } else
            rt = mid - 1;
    }
    cout << res << endl;
    delete[] x;
    return 0;
}