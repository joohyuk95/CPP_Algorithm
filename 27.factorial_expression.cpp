// N! 을 소수들의 곱으로 표현 ex) 5! = 3 2 1
// -> 팩토리얼을 소인수 분해하여 표현
// 팩토리얼은 1부터 N까지 곱해진 수 이므로 1부터 N까지 모든 소수가 적어도 한 번 쓰인다.
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, j;
    cin >> n;
    int *cnt = new int[n+1]();

    for (int i = 2; i <= n; ++i) {
        tmp = i;
        j = 2;
        while (tmp != 1) {
            if (tmp % j == 0) {
                ++cnt[j];
                tmp /= j;
            } else
                ++j;
        }
    }
    cout << n << "! =";
    for (int i = 2; i <= n; ++i) {
        if (cnt[i] != 0)
            cout << ' ' << cnt[i];
    }
    return 0;
}