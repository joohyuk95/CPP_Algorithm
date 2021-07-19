// 진약수의 합 (진약수 : 자기 자신을 제외한 양의 약수)

#include <iostream>
using namespace std;

int main() 
{
    int n, i = 1, sum = 0;
    cout << "input natural numer (3<N<=100)" << endl;
    cin >> n;
    
    while (i < n) {
        if (n % i == 0) {
            sum += i;
            if (i == 1) {
                cout << i;
            } else {
                cout << " + " << i;
            }
        }
        ++i;
    }
    cout << " = " << sum << endl;

    return 0;
}