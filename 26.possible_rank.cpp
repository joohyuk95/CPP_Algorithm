// 자신을 포함한 앞선 수들 중, 자신의 능력 등수 차례대로 출력

#include <iostream>
using namespace std;

int main()
{
    int n, rank;
    cin >> n;
    int *capabilities = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> capabilities[i];
        rank = 1;
        for (int j = 0; j < i; ++j)
            if (capabilities[j] >= capabilities[i])
                ++rank;
        cout << rank << ' ';
    }
    return 0;
}