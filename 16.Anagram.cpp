// 아나그램 : 나열 순서는 다르지만 구성이 동일한 두 단어

#include <iostream>
using namespace std;

int main()
{
    char str1[101], str2[101], size1 = 0, size2 = 0, flag = 1;
    cin >> str1 >> str2;
    for (int i = 0; str1[i] != '\0'; ++i)   // size check
        ++size1;
    for (int i = 0; str2[i] != '\0'; ++i)
        ++size2;

    if (size1 != size2) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < size1 - 1; ++i) {       // selection sorting
            for (int j = i + 1; j < size1; ++j) {
                if (str1[i] > str1[j]) {
                    char tmp1 = str1[i];
                    str1[i] = str1[j];
                    str1[j] = tmp1;
                }
                if (str2[i] > str2[j]) {
                    char tmp2 = str2[i];
                    str2[i] = str2[j];
                    str2[j] = tmp2;
                }
            }
        }
        for (int i = 0; i < size1; ++i) {   // comparing
            if (str1[i] != str2[i]) {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << "YES" << endl;
    }
    return 0;
}