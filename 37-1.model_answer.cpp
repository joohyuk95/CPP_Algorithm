#include <iostream>
using namespace std;
int C[20];

int main() {
    int s, n, a, j, pos;
    cin >> s >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        pos = -1;
        for (j = 0; j < s; ++j) 
            if(C[j] == a) pos = j;
        if (pos == -1) {
            for (j = s-1; j >= 1; --j)
                C[j] = C[j-1];
        } else {
            for (j = pos; j >= 1; --j)
                C[j] = C[j-1];
        }
        C[j] = a;
    }
    for (int i = 0; i < s; ++i)
        cout << C[i] << ' ';
}