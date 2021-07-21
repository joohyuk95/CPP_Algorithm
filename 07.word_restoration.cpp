// 공백제거 및 대문자를 소문자로 출력

#include <iostream>
using namespace std;

int main()
{
    char error[101], correct[101];
    int count = 0;
    cout << "input any error string with space : ";
    cin.getline(error, 101);

    for (int i = 0; error[i] != '\0'; ++i) {
        if (error[i] != ' ') {
            if (error[i] >= 65 && error[i] <= 90)
                correct[count++] = error[i] + 32;
            else
                correct[count++] = error[i];
        }
    }
    cout << correct << endl;

    return 0;
}