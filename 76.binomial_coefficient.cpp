// n과 r이 주어지면 이항계수(nCr) 구하기
// 메모이제이션(memoization) 활용: 프로그램이 동일한 계산을 반복해야 할 때
// 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여, 속도를 향상 시키는 기술
// --> 동적계획법의 핵심
#include <iostream>
using namespace std;
int dp[21][21];

int C(int n, int r)
{
    if (dp[n][r] > 0) return dp[n][r];  // 값이 할당되어 있으면 계산하지 않고, 이미 할당된 값을 바로 반환
    if (n == r || r == 0) return 1;  // nCn or nC0
    else return dp[n][r] = C(n-1, r) + C(n-1, r-1); // 파스칼 삼각형 점화식 nCr = n-1Cr + n-1Cr-1, 값을 저장하면서 동시에 반환
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << C(n, r) << endl;
    return 0;
}