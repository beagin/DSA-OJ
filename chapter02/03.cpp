// by TYY
// 2019.9.27

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int nums[100000];
    char op;  
    // 正整数的个数 操作的个数 操作的参数
    int N, M, k;
    cin >> N >> M;
    
    // 输入数字
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    // 输入操作
    for (int i = 0; i < M; ++i)
    {
        cin >> op >> k;
        // 修改操作
        if (op == 'C')
        {
            for (int j = 0; j < N; ++j)
            {
                nums[j] += k;
                if (nums[j] > 65535)
                    nums[j] -= 65536;
            }
        }
        // 查询操作
        else
        {
            int count = 0;
            for (int j = 0; j < N; ++j)
            {
                if ((nums[j] >> k) % 2 > 0)
                    count++;
            }
            cout << count << endl;
        }
    }

    return 0;
}
