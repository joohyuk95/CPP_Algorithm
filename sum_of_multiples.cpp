// 1부터 N까지 M의 배수합

#include <iostream>
using namespace std;

int main()
{
    int N, M, sum, count;
    cout << "input N, M (3<=M<N<=1000)" << endl;
    cin >> N >> M;

    sum = 0;
    count = 1;
    while (M * count <= N) {
        sum = sum + M * count;
        ++count;
    }

    cout << sum << endl;

    return 0;
}