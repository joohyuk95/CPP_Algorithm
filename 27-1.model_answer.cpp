#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, j, tmp;
    cin >> n;
    vector<int> ch(n+1);
    for(int i = 2; i <= n; ++i) {
        tmp = i;
        j = 2;
        while(1) {
            if (tmp % j == 0) {
                ++ch[j];
                tmp /= j;
            } else
                ++j;
            if (tmp == 1)
                break;
        }
    }
    cout << n << "! =";
    for (int i = 2; i <= n; ++i)
        if (ch[i] != 0)
            cout << ' ' << ch[i];
    cout << endl;
    return 0;
}