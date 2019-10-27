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
public:
    int data;
    HuffmanTreeNode *leftChild;
    HuffmanTreeNode *rightChild;
    HuffmanTreeNode *parent;
    HuffmanTreeNode() { data = 0; leftChild=rightChild=parent=NULL;}
    HuffmanTreeNode(int _data) { data = _data; leftChild=rightChild=parent=NULL;}
    ~HuffmanTreeNode() { 
        leftChild=rightChild=parent=NULL; 
    }
};

/// 
int CalculateSum(const HuffmanTreeNode node, int depth) {
    if (node.leftChild == NULL && node.rightChild == NULL)
        return node.data * depth;
    else
        return CalculateSum(*(node.leftChild), depth+1) + CalculateSum(*(node.rightChild), depth+1);
}

/// vector的排序函数，升序
bool sortByData(const HuffmanTreeNode &htn1, const HuffmanTreeNode &htn2) {
    return htn1.data < htn2.data;
}

class HuffmanTree {
private:
    HuffmanTreeNode *root;      // 根节点
    /// 合并两棵Huffman树ht1与ht2为一棵以parent为根的二叉树
    void MergeTree(HuffmanTreeNode &ht1, HuffmanTreeNode &ht2, HuffmanTreeNode *parent) {
        parent->data = ht1.data + ht2.data;
        parent->leftChild = &ht1;
        parent->rightChild = &ht2;
        ht1.parent = ht2.parent = parent;
        return;
    }

    /// 删除一个Huffman树
    void DeleteTree(HuffmanTreeNode *root) {

    }

public:
    /// 构造函数，生成Huffman树
    HuffmanTree(int weights[], int n) {
        vector<HuffmanTreeNode> NodeList;
        HuffmanTreeNode *parent;
        /// 初始化
        for (int i = 0; i < n; ++i) {
            HuffmanTreeNode temp = HuffmanTreeNode(weights[i]);
            NodeList.push_back(temp);
        }
        /// 进行n-1次合并
        for (int i = 0; i < n-1; ++i) {
            parent = new HuffmanTreeNode(0);
            sort(NodeList.begin()+i*2, NodeList.end(), sortByData);
            MergeTree(NodeList[2*i], NodeList[2*i+1], parent);
            NodeList.push_back(*parent);
            root=parent;
        }
        //NodeList.clear();
    }
    /// 析构函数，删除当前Huffman树
    ~HuffmanTree() { DeleteTree(root); }
    /// 计算Huffman树的外部路径和
    int Calculate() {
        return CalculateSum(*root, 0);
    }
};


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
    HuffmanTree myTree = HuffmanTree(nums, n);
    cout << myTree.Calculate() << endl;

    return 0;
}
