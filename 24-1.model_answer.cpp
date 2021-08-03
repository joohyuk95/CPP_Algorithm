#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, now, pre, pos;
    cin >> n;
    vector <int> ch(n);
    cin >> pre;
    for (int i = 1; i < n; ++i){
        cin >> now;
        pos = abs(pre - now);
        if (pos > 0 && pos < n && ch[pos] == 0) // 인접한 두 값의 차가 0일 수 없고, 차가 중복될 수 없다. n개 자연수로 (n-1)개의 서로 다른 차들이 존재하려면
            ch[pos] = 1;
        else {
            cout << "NO" << endl;
            return 0;
        }
        pre = now;
    }
    cout << "YES" << endl;
    return 0;
}