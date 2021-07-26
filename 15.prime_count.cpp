// 1부터 N까지 소수의 개수 출력 (제한시간 1초), 에라토스테네스의 체

#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cout << "input any natural number (2<=N<=200,000) : ";
    cin >> n;
    bool* PrimeArray = new bool[n + 1];

    for (int i = 2; i <= n; ++i)
        PrimeArray[i] = true;

    for (int i = 2; i * i <= n; ++i) {
        if (PrimeArray[i]) {
            for (int j = i * i; j <= n; j += i) {
                PrimeArray[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (PrimeArray[i])
            ++count;
    }
    cout << count << endl;
    return 0;
}