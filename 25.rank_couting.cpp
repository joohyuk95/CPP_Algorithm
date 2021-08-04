// N명의 점수를 기준으로 순서대로 석차 출력
// key idea : 내 앞에 몇 명 있는가
#include <iostream>
using namespace std;

int main()
{
    int n, rank, score[100], sorted[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> score[i];
    for (int i = 0; i < n; ++i) {
        rank = 1;
        for (int j = 0; j < n; ++j) {
            if (i == j) 
                continue;
            if (score[j] > score[i])
                ++rank;
        }
        cout << rank << ' ';
    }
    return 0;
}