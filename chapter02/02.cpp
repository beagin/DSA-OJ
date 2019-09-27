// by TYY
// 2019.9.27

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int notEmpty[1000][25] = {0};    // 盘子不能为空时的K值
    int M, N, n, k;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        // M: 苹果数 N: 盘子数
        cin >> M >> N;
        // 全部加N个苹果，以保证每个盘子中都有苹果
        M += N;
        // 初始化数组中的某些值
        for (int j = 0; j <= M; ++j)
        {
            notEmpty[j][j] = 1;
            if (j > 0)
                notEmpty[j][1] = 1;
        }
        // 动态规划？
        for (int ii = 1; ii <= M; ++ii)
        {
            for (int jj = 1; jj <= ii; ++jj)
                notEmpty[ii][jj] = notEmpty[ii - 1][jj - 1] + notEmpty[ii - jj][jj];
        }
        cout << notEmpty[M][N] << endl;
    }

    return 0;
}