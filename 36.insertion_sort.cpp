// 삽입정렬
#include <iostream>
using namespace std;

int main()
{
    int n, key;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    for (int i = 1; i < n; ++i) {
        key = nums[i];
        for (int j = i-1; j >= 0; --j) {
            if (nums[j] > key) {
                nums[j+1] = nums[j];
            } else {
                nums[j+1] = key;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << nums[i] << ' ';
    return 0;
}