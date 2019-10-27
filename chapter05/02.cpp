/* Q5.2 Huffman编码
 * by TYY
 * created: 2019.10.27
 * last edit: 2019.10.27
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HuffmanTreeNode {
    int data;
    HuffmanTreeNode *leftChild;
    HuffmanTreeNode *rightChild;
}

class HuffmanTree {
private:
    HuffmanTreeNode *root;
    
}


int main(int argc, char const *argv[])
{
    /// 接受输入
    int n;      // 外部结点的个数
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums+n);     // 对数组进行排序

    

    return 0;
}
