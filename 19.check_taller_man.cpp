// 일렬로 앉았을 때 뒤에 있는 모든 사람보다 앉은 키 큰 사람 수 출력

#include <iostream>
using namespace std;

int main()
{
    int n, height[100], cnt = 0, max;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> height[i];
    max = height[n-1];
    for (int i = n-2; i >= 0; --i) {
        if (height[i] > max) {
            max = height[i];
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}