// 오름차순 두 배열을 합친 오름차순 출력
#include <iostream>
using namespace std;

int main()
{
    int n, m, a = 0, b = 0;
    cin >> n;
    int *nums1 = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> nums1[i];
    cin >> m;
    int *nums2 = new int[m];
    for (int i = 0; i < m; ++i)
        cin >> nums2[i];
    int *merge = new int[n+m];

    for (int i = 0; i < n+m; ++i) {
        if (nums1[a] > nums2[b] || a >= n) {
            merge[i] = nums2[b];
            ++b;
        } else {
            merge[i] = nums1[a];
            ++a;
        }
    }
    for (int i = 0; i < n+m; ++i)
        cout << merge[i] << ' ';

    return 0;
}