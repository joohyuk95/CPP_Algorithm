// 선택정렬
#include <iostream>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (nums[i] > nums[j]) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << nums[i] << ' ';

    return 0;
}