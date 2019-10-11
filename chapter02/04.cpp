#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool function(vector<int> &seq)
{
    int n = seq.size();             // 序列长度
    int cur_index, pre_index = 0;   // 记录前一个索引与当前索引
    // 创建一个range(1, n)的vector，记录剩余的编号
    vector<int> temp;
    for(int i = 0; i < n; ++i)
        temp.push_back(i+1);

    for (int i = 0; i < n - 1; ++i)
    {
        // 获取当前出栈的编号在temp中的索引
        vector<int>::iterator iter = find(temp.begin(), temp.end(), seq[i]);
        if (iter == temp.end())
            return false;
        cur_index = distance(temp.begin(), iter);

        if (cur_index >= pre_index)
        {
            pre_index = cur_index - 1;
            temp.erase(iter);   // 将当前编号从temp中删除
        }
        else
            return false;
    }
    return true;
}
