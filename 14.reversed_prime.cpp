// 자연수를 뒤집어서 소수이면 출력

#include <iostream>
using namespace std;

int reverse(int x)
{
    int res = 0;
    while (x > 0) {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}
bool isPrime(int x)
{
    bool prime = true;
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    int n, num[100] = {0, };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        num[i] = reverse(num[i]);
        if (isPrime(num[i]) == true) {
            cout << num[i] << ' ';
        }
    }
    return 0;
}