#include <iostream>
using namespace std;
char tmp[31];
int stack[31], top = -1;

void push(int x)
{
    stack[++top] = x;
}

int main()
{
    cin >> tmp;
    for (int i = 0; tmp[i] != 0; ++i)
        push(tmp[i]);
        
    if (top % 2 == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}