#include <iostream>
using namespace std;

int a[60], b[60];

int main()
{
    int n;
    char str[100];
    cin >> str;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 65 && str[i] <= 90)
            a[str[i] - 64]++;               // index 1부터 26까지 대문자 알파벳의 카운팅
        else
            a[str[i] - 70]++;               // index 27부터 52까지 소문자 알파벳의 카운팅
    }

    cin >> str;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 65 && str[i] <= 90)
            b[str[i] - 64]++;
        else
            b[str[i] - 70]++;
    }

    for (int i = 0; i <= 52; ++i) {
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    return 0;
}