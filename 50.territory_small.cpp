// 전체 땅의 크기와 영지의 크기가 주어지면, 영지의 오렌지 나무 개수 최댓값을 출력
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream data;
    data.open("50_data.txt");

    int h_earth, w_earth, h_territory, w_territory, sum, max = 0;
    cin >> h_earth >> w_earth;
    int **earth = new int *[h_earth];
    for (int i = 0; i < h_earth; ++i)
        earth[i] = new int [w_earth];
    for (int i = 0; i < h_earth; ++i)
        for (int j = 0; j < w_earth; ++j)
            data >> earth[i][j];
    cin >> h_territory >> w_territory;

    for (int i = 0; i < h_earth - (h_territory-1); ++i) {
        for (int j = 0; j < w_earth - (w_territory-1); ++j) {
            sum = 0;
            for (int h = i; h < i + h_territory; ++h) {
                for (int w = j; w < j + w_territory; ++w) {
                    sum += earth[h][w];
                }
            }
            if (sum > max) max = sum;
        }
    }
    cout << max << endl;
    for (int i = 0; i < h_earth; ++i)
        delete[] earth[i];
    delete[] earth;
    return 0;
}