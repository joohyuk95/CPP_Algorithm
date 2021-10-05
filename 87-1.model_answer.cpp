#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n, map[30][30], cnt;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

class Loc {
public:
    int x;
    int y;
    Loc(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
};
queue<Loc> Q;

int main()
{
    ifstream data;
    data.open("./87_data.txt");
    data >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) data >> map[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1) {
                Q.push(Loc(i, j));
                map[i][j] = 0;
                while (!Q.empty()) {
                    Loc tmp = Q.front();
                    Q.pop();
                    for (int k = 0; k < 8; ++k) {
                        int xx = tmp.x + dx[k];
                        int yy = tmp.y + dy[k];
                        if (map[xx][yy] == 1) {
                            Q.push(Loc(xx, yy));
                            map[xx][yy] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}