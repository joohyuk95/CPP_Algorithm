// 1. 벽돌의 옆면을 밑면으로 사용할 수 없다. (밑면은 정사각형)
// 2. 밑면의 넓이와 무게는 모두 다름, 높이는 같을 수도
// 3. 위에 놓이는 벽돌은 반드시 밑의 벽돌보다 무게가 무겁고 밑면이 좁음
// 벽돌 종류의 수, 각 벽돌의 밑면 넓이, 높이, 무게 정보가 주어지면 가장 높이 쌓을 수 있는 탑의 높이를 출력
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Brick {
public:
    int bottom, height, weight;
    Brick(int a, int b, int c) {
       this->bottom = a;
       this->height = b;
       this->weight = c; 
    }
    bool operator<(const Brick &b) const
    {
        return this->bottom > b.bottom;  // 밑면 면적을 기준으로 내림차순 정렬
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream data;
    data.open("./97_data.txt");
    int n, a, b, c;
    data >> n;
    vector<Brick> Bricks;
    vector<int> dp(n);  // dp[i] : i번 째 블록을 최상단에 쌓았을 때 최대 높이

    for (int i = 0; i < n; ++i) {
        data >> a >> b >> c;
        Bricks.push_back(Brick(a, b, c));
    }
    sort(Bricks.begin(), Bricks.end());
    dp[0] = Bricks[0].height;
    int res = dp[0];
    for (int i = 1; i < n; ++i) { 
        int max_h = 0;
        for (int j = i-1; j >= 0; --j) {
            if (Bricks[i].weight < Bricks[j].weight && dp[j] > max_h) max_h = dp[j];
        }
        dp[i] = max_h + Bricks[i].height;
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}