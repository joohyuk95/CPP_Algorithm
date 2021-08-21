// n, m 주어지면 n개의 수를 입력 받아 오름차순 정렬 후, 이분검색으로 m의 인덱스 찾기
#include <iostream>
using namespace std;

int main()
{
    int n, m, key, j, lt = 1, rt, half;
    cin >> n >> m;
    int *nums = new int[n+1];
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    for (int i = 2; i < n+1; ++i) {
        key = nums[i];
        for (j = i-1; j >= 1; --j) {
            if (nums[j] > key)
                nums[j+1] = nums[j];
            else
                break;
        }
        nums[j+1] = key;
    }

    rt = n;
    int cnt = 1;
    while (lt <= rt) {
        half = (lt + rt) / 2;
        if (nums[half] == m)
            break;
        else if (nums[half] > m)
            rt = half - 1;
        else
            lt = half + 1;
        ++cnt;
    }
    cout << half << endl;
    return 0;
}