/* Q5.1 由中根序列和后根序列重建二叉树
 * by TYY
 * created: 2019.10.24
 * last edit: 2019.10.25
 */

#include <iostream>
using namespace std;
const int MAXNUM = 10000;
int postOrder[MAXNUM], inOrder[MAXNUM];

/* 根据中序和后序序列得到前序
 * sindex_in, eindex_in：中根序列的首尾坐标
 * sindex_post, eindex_post：后根序列的首尾坐标
 */
void getPre(int sindex_in, int eindex_in, int sindex_post, int eindex_post) {
    /// 获取根节点的值并输出
    int root = postOrder[eindex_post];      
    cout << root << ' ';
    /// 如果总长度为1则直接返回
    if (eindex_in == sindex_in) {
        return;
    }
    /// 在中根序列中找到根节点的位置
    int root_in=-1;
    for (int i = sindex_in; i <= eindex_in; ++i) {
        if (inOrder[i] == root)
            root_in = i;
    }
    if (root_in < 0) {
        cout << "error" << endl;
        return;
    }
    /// 获取后根序列中的左右子树长度
    int len_left = root_in - sindex_in;                 // 左子树长度
    int len_right = eindex_in - len_left - sindex_in;   // 右子树长度
    /// 进行递归
    // 左子树
    if (len_left > 0)
        getPre(sindex_in, root_in-1, sindex_post, sindex_post+len_left-1);
    // 右子树
    if (len_right > 0)
        getPre(root_in+1, eindex_in, sindex_post+len_left, eindex_post-1); 
    return;
}


int main(int argc, char const *argv[])
{
    /// 接受输入（中序与后序遍历）
    int i = 0;
    while (cin >> inOrder[i++])
        if (cin.get() != ' ')
            break;
    i = 0;
    while (cin >> postOrder[i++])
        if (cin.get() != ' ')
            break;

    /// 开始递归
    getPre(0, i-1, 0, i-1);
    cout << endl;
    return 0;
}


