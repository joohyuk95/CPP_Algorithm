// 10진수 N을 K진수로 변환 (k = 2, 5, 8, 16)
#include <iostream>
using namespace std; 
char transform[1000];

int main()
{
    int n, k, tmp, i = 0;
    cin >> n >> k;

    tmp = n;
    while (true) {
        if (tmp >= k) {
            if (tmp % k >= 10) transform[i] = tmp % k + 55;
            else transform[i] = tmp % k + 48;
            tmp /= k;
        } else {
            if (tmp >= 10) transform[i] = tmp + 55;
            else transform[i] = tmp + 48;
            break;
        }
        ++i;
    }
    for (int j = i; j >= 0; --j)
        cout << transform[j];
    cout << endl;
    return 0;
}