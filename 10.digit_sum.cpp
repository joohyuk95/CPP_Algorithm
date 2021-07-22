// 자릿수의 합이 최대인 자연수를 출력

#include <iostream>
using namespace std;

int digit_sum(int x)
{
    int sum = 0, count = 0;
    
    while (1) {
        sum += x % 10;
        x /= 10;
        if (x == 0)
            break;
    }
    return sum;    
}

int main()
{
    int n, index = 0, numbers[100], digits[100];
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        digits[i] = digit_sum(numbers[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        if (digits[i] > digits[index] || (digits[i] == digits[index] && numbers[i] > numbers[index]))
            index = i;
    }
    cout << numbers[index] << endl;
    return 0;
}