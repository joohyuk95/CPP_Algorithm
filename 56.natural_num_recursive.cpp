// n을 입력하면 재귀함수를 사용해서 1부터 n까지 출력
#include <iostream>
using namespace std;

void one2n(int x)
{
    if (x == 0) return;
    else {
        one2n(x-1);
        cout << x << ' ';
    }
}

int main()
{
    int n;
    cin >> n;
    one2n(n);
    cout << endl;
    return 0;
}