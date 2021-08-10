// 탄화수소 질량 계산, CxHy,  (C : 12, H : 1)

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, c_mass, h_mass, res;
    string ch, c, h;
    cin >> ch;
   
    for (i = 1; ch[i] != 'H'; ++i)
        c += ch[i];
    for (int j = i+1; ch[j] != '\0'; ++j)
        h += ch[j]; 

    if (c[0] == '\0') c_mass = 12;
    else c_mass = 12 * stoi(c);
    
    if (h[0] == '\0') h_mass = 1;
    else h_mass = stoi(h);

    res = c_mass + h_mass;
    cout << res << endl;
    return 0;
}