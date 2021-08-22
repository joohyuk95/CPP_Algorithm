#include <iostream>
using namespace std;
int a[1001], n;

int Count(int s)
{
    int cnt = 1, sum = 0;
    for (int i = 0; i <= n; ++i) {
        if (sum + a[i] > s) {
            cnt++;
            sum = a[i];
        } else
            sum += a[i];
    }
    return cnt;
}

int main()
{
    int m, lt = 1, rt = 0, mid, res, maxx = -2147000000;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        rt += a[i]; // rt = 입력의 총합
        if (a[i] > maxx) maxx = a[i];   // 최댓값 저장
    }
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        if (mid >= maxx && Count(mid) <= m) {
            res = mid;
            rt = mid - 1;
        } else
            lt = mid + 1;
    }
    cout << res << endl;
    return 0;
}