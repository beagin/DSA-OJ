/* Q5.1 由中根序列和后根序列重建二叉树
 * by TYY
 * created: 2019.10.24
 * last edit: 2019.10.25
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
constexpr int MAXNUM = 10000;
int postOrder[MAXNUM], inOrder[MAXNUM], preOrder[MAXNUM];

/* 根据中序和后序序列得到前序
 * sindex_in, eindex_in：中根序列的首尾坐标
 * sindex_post, eindex_post：后根序列的首尾坐标
 */
void getPre(int sindex_in, int eindex_in, int sindex_post, int eindex_post) {
    /// 获取根节点的值并输出
    int root = postOrder[eindex_post];      
    cout << root << ' ';
    /// 如果总长度为3则直接输出左右叶节点的值
    if (eindex_in - sindex_in == 2) {
        cout << postOrder[sindex_post] << ' ' << postOrder[eindex_post];
        return;
    }
    /// 在中根序列中找到根节点的位置
    int root_in=-1;
    for (int i = sindex_in+1; i < eindex_in; ++i) {
        if (inOrder[i] == root)
            root_in = i;
    }
    if (root_in < 0) {
        cout << "error" << endl;
        return;
    }
    /// 获取后根序列中的左右子树
    int len_left = root_in - sin
    // 进行递归
    

}


int main(int argc, char const *argv[])
{
    /// 接受输入（中序与后序遍历）
    int i=0;
    while (cin >> inOrder[i++])
        if (cin.get() != ' ')
            break;
    while (cin >> postOrder[i++])
        if (cin.get() != ' ')
            break;

    /// 

    return 0;
}


