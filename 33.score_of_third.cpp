// 3등 성적이 아니고 3번 째 높은 성적을 출력 (공동 등수 가능, 1등이 2명 이상이라도 2등 존재)
#include <iostream>
using namespace std;

int main()
{
    int n, tmp, rank = 1;
    cin >> n;
    int *scores = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> scores[i];
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (scores[j] > scores[i]) {
                tmp = scores[i];
                scores[i] = scores[j];
                scores[j] = tmp;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (scores[i-1] > scores[i]) {
            ++rank;
            if (rank == 3)
                cout << scores[i] << endl;
        }
    }
    return 0;
}