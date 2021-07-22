// 9번 모범 답안

#include <iostream>
using namespace std;
int cnt[50001];

int main()
{
    int n, i, j;
    cin >> n;
    for (i = 1; j <= n; ++i) {
        for (j = i; j <=n ; j+=i) {     // 각 자연수에 대해서 약수를 구하는게 아니라
            cnt[j]++;                   // 1부터 n까지 i의 배수일 때마다 j번째 자연수의 약수 개수를 하나씩 카운팅함. (i는 j의 약수)
        }
    }
    for (i = 1; i <= n; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << endl;

    return 0;
}