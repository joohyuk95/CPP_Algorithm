// N개의 정수 수열에 대해서 인접한 두 수의 차가 1에서 N-1까지 모두 가지면 YES
#include <iostream>
using namespace std;

int main()
{
    int n, index, nums[100], check[100] = {0, };
    cin >> n;
    cin >> nums[0];
    for (int i = 1; i < n; ++i) {
        cin >> nums[i];
        index = abs(nums[i] - nums[i-1]);
        check[index] = 1;
    }
    for (int i = 1; i <= n-1; ++i) {
        if (check[i] == 0) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    return 0;
}