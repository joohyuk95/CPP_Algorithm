// 최대힙 : 완전이진트리로 구현된 자료구조, 부모노드가 자식노드보다 큰 값
// 100,000개 이하의 자연수를 입력하면 최대힙에 입력됨
// 숫자 0이 입력되면 최대힙에서 최댓값을 '꺼내어' 출력하고 출력할 자료가 없으며 -1 출력하고 프로그램 종료
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    ifstream data;
    data.open("./73_data.txt");
    priority_queue<int> pq;
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