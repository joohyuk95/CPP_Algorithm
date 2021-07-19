// N개의 자연수를 입력받아 최댓값과 최솟값의 차를 출력

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "input the number of people (2<=N<=100)" << endl;
    cin >> n;

    int age[100] = {0, };
    for (int i = 0; i < n; ++i) {
        cin >> age[i];
    }

    // bubble sorting
    for (int i = n-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (age[j] > age[j+1]) {
                int tmp = age[j];
                age[j] = age[j+1];
                age[j+1] = tmp;
            }
        }
    }
    cout << age[n-1] - age[0] << endl;

    return 0;
}