// 11번 모범답안

#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0, tmp;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        tmp = i;
        while (tmp > 0) {
            tmp /= 10;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}