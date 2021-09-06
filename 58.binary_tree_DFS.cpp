// 이진트리 깊이우선탐색(DFS)
#include <iostream>
using namespace std;

void DFS(int x)
{
    if (x > 7) return;
    else {
        cout << x << ' ';   // 전위순회 (preorder)
        DFS(x*2);
        DFS(x*2+1);
    }
}

int main()
{
    DFS(1);
    return 0;
}