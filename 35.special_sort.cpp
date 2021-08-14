// 입력된 정수를 음수와 양수로 정렬 (입력된 순서는 변하지 않음)
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, neg_index = 0, pos_index = 0;
    cin >> n;
    int *neg = new int[n]();
    int *pos = new int[n]();
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < 0) {
            neg[neg_index] = tmp;
            ++neg_index;
        } else {
            pos[pos_index] = tmp;
            ++pos_index;
        }
    }
    for (int i = 0; neg[i] != 0; ++i)
        cout << neg[i] << ' ';
    for (int i = 0; pos[i] != 0; ++i)
        cout << pos[i] << ' ';
    return 0;
}