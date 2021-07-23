// 1부터 N까지 자릿수들을 찢어서 나열했을 때, 숫자의 총 개수

#include <iostream>
using namespace std;

int main()
{
    int n, x = 1, digit = 0, count = 0, first = 1;
    cout << "input any natural number (3<=N<100,000) : ";
    cin >> n;

    while (n / x != 0) {
        ++digit;
        x *= 10;
    }
    while (digit != 0) {
        x /= 10;
        if (first == 1) {
            count += (n - x + 1) * digit;
            first = 0;
        } else {
            count += (x * 10 - x) * digit;
        }
        --digit;
    }
    cout << count << endl;

    return 0;
}