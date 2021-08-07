// N!의 1의 자리부터 연속된 0의 개수 출력
// (10 <= N <= 1,000)
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, two = 0, five = 0;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        tmp = i;
        while (tmp % 2 == 0) {
            ++two;
            tmp /= 2; 
        }
        while (tmp % 5 == 0) {
            ++five;
            tmp /= 5;
        }
    }
    
    if (two != 0 && five != 0) {
        if (two >= five)
            cout << five << endl;
        else
            cout << two << endl;
    } else
        cout << '0' << endl;
    return 0;
}