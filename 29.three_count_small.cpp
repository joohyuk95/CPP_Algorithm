// 1부터 N까지 3의 개수는?

#include <iostream>
using namespace std;

int main()
{
    int n, tmp, cnt = 0;
    cin >> n;
    for (int i = 3; i <= n; ++i) {
        tmp = i;
        while (tmp != 0) {
            if (tmp % 10 == 3)
                ++cnt;
            tmp /= 10;
        }
    }
    cout << cnt << endl;
    return 0;
}