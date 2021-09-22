// 최대힙과 반대, 부모 노드가 자식노드보다 값이 작음
// 우선순위 큐 활용
#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    ifstream data;
    data.open("./73_data.txt");
    priority_queue<int, vector<int>, greater<int>> pq;
    int a;
    while (true) {
        data >> a;
        if (a == -1) break;
        if (a == 0) {
            if (pq.empty())
                cout << -1 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else pq.push(a);
    }
    return 0;
}