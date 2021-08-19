// 교집합의 오름차순을 출력
#include <iostream>
using namespace std;

int main()
{
    int n, m, tmp;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] > A[j+1]) {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }

    cin >> m;
    int *B = new int[m];
    for (int i = 0; i < m; ++i)
        cin >> B[i];
    for (int i = m-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (B[j] > B[j+1]) {
                tmp = B[j];
                B[j] = B[j+1];
                B[j+1] = tmp;
            }
        }
    }    
    int *inter = new int[n]();
    tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i] == B[j]) {
                inter[tmp++] = A[i];
                break;
            }
        }
    }
    for (int i = 0; inter[i] != 0; ++i)
        cout << inter[i] << ' ';
    return 0;
}