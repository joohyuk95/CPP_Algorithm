#include <iostream>
#include <stack>
#include <vector>
using namespace std;			

int main() 
{
	stack <int> s;
	int i, j = 1, n, m;
	cin >> n;
	vector <char> str;
	for (int i = 1; i <= n; ++i){
		cin >> m;
		s.push(m);
		str.push_back('P');
		while (1) {
			if (s.empty()) break;
			if (j == s.top()) {
				s.pop();
				j++;
				str.push_back('O');
			}
			else break;
		}
	}
	if(!s.empty()) cout << "impossible" << endl;
	else {
		for (int i = 0; i < str.size(); ++i) cout << str[i];
	}
    cout << endl;
	return 0;
}
