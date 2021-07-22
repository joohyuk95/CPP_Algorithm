// 1부터 N까지 각 자연수 약수의 개수 출력

#include <iostream>
using namespace std;

int main()
{
    cout << "input any natural number (5<=N<=50,000) : ";
    int n, count = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0)
                ++count;
        }
        cout << count << ' ';
        count = 0;
    }
    return 0;
}
