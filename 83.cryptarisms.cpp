// SEND + MORE = MONEY 복면산
// 같은 문자는 같은 숫자, 숫자는 중복되지 않고, 첫 번째 자리 수는 0이 아니다.
#include <iostream>
using namespace std;
int a[10], ch[10];  // s e n d m o r y

int send()
{
    return a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
}
int more()
{
    return a[4]*1000 + a[5]*100 + a[6]*10 + a[1];
}
int money()
{
    return a[4]*10000 + a[5]*1000 + a[2]*100 + a[1]*10 + a[7];
}

void DFS(int x)
{
    if (x == 8) {
        if (send() + more() == money()) {
            if (a[0] == 0 || a[4] == 0) return;
            cout << "  " << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
            cout << "+ " << a[4] << ' ' << a[5] << ' ' << a[6] << ' ' << a[1] << endl;
            cout << "----------" << endl;
            cout << a[4] << ' ' << a[5] << ' ' << a[2] << ' ' << a[1] << ' ' << a[7] <<endl;
        } 
    } else {
        for (int i = 0; i < 10; ++i) {
            if (ch[i] == 0) {
                a[x] = i;
                ch[i] = 1;  // 0 ~ 9 중 사용된 숫자 체크
                DFS(x + 1);
                ch[i] = 0;
            }
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}