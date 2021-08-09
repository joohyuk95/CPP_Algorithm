// 1부터 N까지 3의 개수 (3<=N<=10억)
#include <iostream>
using namespace std;

int main()
{
    int n, left = 1, cur, right, k = 1, cnt = 0;
    cin >> n;

    while (left != 0) {
        left = n / (10 * k);
        cur = (n % (10 * k)) / k;
        right = (n % k) + 1;

        if (cur > 3) {
            cnt += (left + 1) * k;
        } else if (cur == 3) {
            cnt += (left * k) + right;
        } else {
            cnt += left * k;
        }
        k *= 10;
    }
    cout << cnt << endl;
    return 0;
}