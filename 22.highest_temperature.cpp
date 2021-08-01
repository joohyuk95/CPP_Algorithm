// n일 간의 측정된 온도 중, 연속된 k일 간 온도 합의 최댓값 출력
// (2<=n<=100,000), (1<=k<=n), (-100<=온도<=100)
#include <iostream>
using namespace std;

int main()
{
    int n, k, max = -300;
    cin >> n >> k;
    int *temperature = new int[n];
    int *sum = new int[n]();
    for (int i = 0; i < n; ++i)
        cin >> temperature[i];

    for (int i = 0; i < n-(k-1); ++i) {
        for (int j = i; j < i+k; ++j)
            sum[i] += temperature[j];
        if (sum[i] > max)
            max = sum[i];
    }
    cout << max << endl;
    delete[] temperature;
    delete[] sum;
    return 0;
}