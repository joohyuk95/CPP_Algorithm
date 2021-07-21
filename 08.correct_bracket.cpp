#include <iostream>
using namespace std;

int main()
{
    char bracket[31];
    int l_count = 0, r_count = 0;
    cout << "input brackets : ";
    cin >> bracket;

    for (int i = 0; bracket[i] != '\0'; ++i) {
        if (bracket[i] == '(')
            ++l_count;
        else
            ++r_count;
    }
    if (l_count == r_count)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}