// n개의 작업을 1초씩 처리, 새로운 작업은 들어오지 않음
// k초 후에 정전이 되었다면 몇 번째부터 다시 작업해야하는지 출력
#include <iostream>
using namespace std;
int n;
int Count(int time[])
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (time[i] != 0) ++cnt;
    return cnt;
}

int main()
{
    int k, j, work;
    cin >> n;
    int *time = new int[n+1];
    for (int i = 1; i <= n; ++i)
        cin >> time[i];
    cin >> k;
    j = 0;
    while (j+1 <= k) {
        work = (j % n) + 1;
        if (time[work] != 0) --time[work];
        ++j;
    }
    if (Count(time) == 0)
        cout << -1 << endl;
    else
        cout << (j % n) + 1 << endl;

    delete[] time;
    return 0;
}