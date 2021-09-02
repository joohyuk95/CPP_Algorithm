#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <char> s;
    string str;
    cin >> str;
    for (auto x : str) {    // 범위 기반 for 문, for (element_declaration : array), auto는 타입추론 (알아서 형식 맞춰줌)
        if (x == '(') s.push(x);
        else {
            if (s.empty() || s.top() != '(') {
                cout << "NO";
                return 0;
            }
            s.pop(); // 짝 없애기
        }
    }
    if (s.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}