// 45번 동일문제 (큐 자료구조로 해결)
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        Q.push(i);
    
    while (Q.size() != 1) {
        for (int i = 1; i < k; ++i){
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
    }
    cout << Q.front() << endl;
    return 0;
}