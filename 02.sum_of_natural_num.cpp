// 자연수의 합

#include <iostream>
using namespace std;

int main()
{
	int A, B, sum;
	cout << "input natural numbers A, B (1<=A<B<=100)" << endl;
	cin >> A >> B;

	sum = 0;
	for (int i = A; i <= B; ++i) {
		sum = sum + i;
		if (i == B) {
			cout << i << " = " << sum << endl;
		}
		else {
			cout << i << " + ";
		}
	}
	return 0;
}