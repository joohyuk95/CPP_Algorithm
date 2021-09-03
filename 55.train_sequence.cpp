// 교차로(stack)를 활용하여 기차를 순서대로 도착하게 만들기
// 모든 기차는 반드시 교차로를 지남
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, m, seq = 1;
    cin >> n;
    stack <int> s;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        s.push(m); str += 'P';
        while (true) {
            if (s.empty()) break;
            else if (s.top() == seq) {
                s.pop(); str += 'O';
                ++seq;
            }
            else break;
        }
    }
    if (s.empty()) cout << str << endl;
    else cout << "impossible" << endl;
    return 0;
}