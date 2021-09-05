// 재귀함수를 사용해서 10진수 N을 2진수로 변환
#include <iostream>
using namespace std;

void decimal_to_bynary(int x)
{
    if (x == 0) {
        cout << endl;
        return;
    } else {
        decimal_to_bynary(x / 2);
        cout << x % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    decimal_to_bynary(n);
    return 0;
}