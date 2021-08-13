// 버블정렬
#include <iostream>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j+1]) {
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << ' ';
    }
    return 0;
}