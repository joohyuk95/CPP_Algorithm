// ugly number : 소인수분해 결과 2, 3, 5로 이루어진 수, 1을 포함한다.
// n번 째 ugly number 출력하기
#include <iostream>
using namespace std;

int main()
{
    int n, num = 2, tmp, cnt = 1;
    cin >> n;

    while (true) {
        tmp = num;
        while (tmp % 2 == 0)
            tmp /= 2;
        while (tmp % 3 == 0)
            tmp /= 3;
        while (tmp % 5 == 0)
            tmp /= 5;
        if (tmp == 1) {
            ++cnt;
            if (cnt == n) {
                cout << num << endl;
                break;
            }
        }
        ++num;
    }
    return 0;
}