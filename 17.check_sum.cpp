// 학생 수를 입력받고 각 학생이 부여받은 1~1000 범위의 자연수와
// 1부터 그 자연수까지의 합을 입력. 정답 여부를 YES, NO로 출력

#include <iostream>
using namespace std;

int main()
{
    int n, end[10], answer[10], sum[10] = {0, };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> end[i];
        cin >> answer[i];
        for (int j = 1; j <= end[i]; ++j)
            sum[i] += j;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if (answer[i] == sum[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}