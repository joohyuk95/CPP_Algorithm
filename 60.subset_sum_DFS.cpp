// n개의 원소를 가지는 집합을 두 개의 부분집합으로 나눴을 때, 합이 같은 것이 존재하면 YES 출력
#include <iostream>
using namespace std;
int n, sum, subset_sum, subset[10], ch[100];
bool flag = false;

void DFS(int x)
{
    if (flag) return;
    if (x == n){
        subset_sum = 0;
        for (int i = 0; i < n; ++i)
            if (ch[i] == 1) subset_sum += subset[i];
        if (subset_sum == (sum / 2))
            flag = true;  
    } else {
        ch[x] = 1;
        DFS(x + 1);
        ch[x] = 0;
        DFS(x + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> subset[i];
        sum += subset[i];
    }
    DFS(0);
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}