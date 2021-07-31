// 가위바위보 승자 출력 (1:가위, 2:바위, 3:보)

#include <iostream>
using namespace std;

int main()
{
    int n, A[100], B[100];
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    for (int i = 0; i < n; ++i) {
        if (A[i] == B[i])
            cout << 'D' << endl;
        else {
            switch (A[i] - B[i]) {
                case 1:
                case -2:
                    cout << 'A' << endl;
                    break;
                default:
                    cout << 'B' << endl;       
            }
        }
    }
    return 0;
}