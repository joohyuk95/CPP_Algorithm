// 입력된 숫자의 자릿수 중, 가장 많이 사용된 숫자를 출력

#include <iostream>
using namespace std;

int main()
{
    char n[101];
    int count[10] = {0, }, max = 0;
    cout << "input any natural number : ";
    cin >> n;
    for (int i = 0; n[i] != '\0'; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (n[i] - 48 == j) {
                ++count[j];
                break;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << count[i] << ' ';
        if (count[i] > count[max] || (count[i] == count[max] && i > max)) 
            max = i;
    }
    cout << endl << max << endl;

    return 0;
}