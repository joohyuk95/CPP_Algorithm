// 0~9까지 10장의 카드로 게임. 비교해서 이기면 3점 비기면 1점
// 차례대로 비교해서 승점이 높으면 이김.
// 승점이 같은 경우, 승부가 난 마지막 라운드 기준으로 승자 결정.
// 모든 라운드를 비겼을 때만 비김.

#include <iostream>
using namespace std;

int main()
{
    int A[10], B[10], A_score = 0, B_score = 0, index, cnt = 0;
    for (int i = 0; i < 10; ++i)
        cin >> A[i];
    for (int i = 0; i < 10; ++i)
        cin >> B[i];
    
    for (int i = 0; i < 10; ++i) {
        if (A[i] > B[i]) {
            A_score += 3;
        } else if (A[i] < B[i]) {
            B_score += 3;
        } else {
            ++cnt;
            index = i;
            ++A_score;
            ++B_score;
        }
    }
    cout << A_score << ' ' << B_score << endl;
    if (A_score > B_score) {
        cout << 'A' << endl;
    } else if (A_score < B_score) {
        cout << 'B' << endl;
    } else {
        if (cnt != 10) {
            if (A[index] > B[index])
                cout << 'A' << endl;
            else
                cout << 'B' << endl; 
        } else {
            cout << 'D' << endl;
        }
    }
    return 0;
}