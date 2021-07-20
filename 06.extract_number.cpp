// 문자와 숫자 섞인 문자열에서 숫자추출

#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "input random string : ";
    cin >> str;

    int sum = 0, divisor_count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] > 47 && str[i] < 58) {
            sum = sum * 10 + (str[i] - 48);
        }
    }

    for (int i = 1; i <= sum; ++i) {
        if (sum % i == 0)
            ++divisor_count;
    }
    cout << sum << endl << divisor_count << endl;

    return 0;
}