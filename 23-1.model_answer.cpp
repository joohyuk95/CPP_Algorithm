#include <iostream>
using namespace std;

int main()
{
    int n, pre, now, cnt = 1, max = 1;
    cin >> n >> pre;
    for (int i = 2; i <= n; ++i) {
        cin >> now;
        if (now >= pre) {
            ++cnt;
            if (cnt > max) max = cnt;
        } 
        else cnt = 1;
        pre = now;    
    }
    cout << max << endl;
    return 0;
}