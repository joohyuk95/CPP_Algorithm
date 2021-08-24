// n명의 왕자, 1번부터 순서대로 번호를 외침
// k를 외치면 제외되고 다음 순번부터 다시 번호, 마지막에 남는 왕자는 몇번?
#include <iostream>
using namespace std;
int n, res;

int Count(int nums[])
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (nums[i] != 0) ++cnt;
    return cnt;
}

int main()
{
    int k, tmp = 0, who, k_cnt, j;
    cin >> n >> k;
    int *nums = new int[n+1];
    for (int i = 1; i <= n; ++i)
        nums[i] = i;
    
    while (Count(nums) != 1) {
        k_cnt = 0;
        while (true) {
            who = (tmp % n) + 1;
            if (nums[who] != 0) {
                ++k_cnt;
                if (k_cnt == k) {
                    nums[who] = 0;
                    ++tmp;
                    break;
                }
            }
            ++tmp;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (nums[i] != 0)
            cout << nums[i] << endl;
    delete[] nums;
    return 0;
}