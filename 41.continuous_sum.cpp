// 2개 이상의 연속된 자연수 합으로 정수 N을 표현하는 방법 출력
#include <iostream>
using namespace std;

int main()
{
    int n, half, sum, cnt = 0;
    cin >> n;
    if (n % 2 == 0)
        half = n / 2;
    else
        half = n / 2 + 1;
    
    for (int i = half; i > 2; --i) {
        sum = i;
        for (int j = i-1; j >= 0; --j) {
            sum += j;
            if (sum == n) {
                for (int k = j; k <= i; ++k) {
                    if (k == i) cout << k << " = " << n << endl;
                    else cout << k << " + ";
                }
                ++cnt;
                break;
            } else if (sum > n) {
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}