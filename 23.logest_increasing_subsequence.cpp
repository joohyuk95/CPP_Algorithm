// 나열된 수열 중 연속적으로 증가하는 부분수열의 최대 길이 출력
// 값이 같을 때는 증가하는 것으로 생각 

#include <iostream>
using namespace std;

int main()
{
    int n, max_length = 0, tmp_length = 1;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i == 0)
            continue;
        if (nums[i] >= nums[i-1])
            ++tmp_length;
        else {
            if (tmp_length > max_length)
                max_length = tmp_length;
            tmp_length = 1;
        }
    }
    cout << max_length << endl;
    return 0;
}