// CPU 캐시메모리의 LRU 알고리즘
#include <iostream>
using namespace std;

int main()
{
    int s, n, work, j, tmp, hit, index;
    cin >> s >> n;
    int *cache = new int[n]();
    for (int i = 0; i < s; ++i) {
        for (int j = i; j >= 1; --j) {
            cache[j] = cache[j-1];
        }
        cin >> cache[0];
    }
    
    for (int i = 0; i < n-s; ++i) {
        cin >> work;
        for (int j = 0; j < s; ++j) {
            hit = 0;
            if (cache[j] == work) {
                hit = 1;
                index = j;
                break;
            }
        }
        if (hit)
            for (int i = index; i >= 1; --i)
                cache[i] = cache[i-1];
        else
            for (int i = s-1; i >= 1; --i)
                cache[i] = cache[i-1];
        cache[0] = work;
    }
    for (int i = 0; i < s; ++i)
        cout << cache[i] << ' ';
    return 0;
}