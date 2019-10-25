/* 书面作业 
 * 4.1 以链表存储字符串，写一个时间复杂度为O(len(S))的算法判定字符出啊是否有对称性
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    char data;
    ListNode *next;
};

typedef ListNode *ListPtr;

struct LString
{
    ListPtr head;
    int strLen;
};

bool isSymmetrical(LString S) {
    float middle = (S.strLen-1) / 2;   // 字符串正中间的索引值
    int index = 0;
    char *all = new char[S.strLen];
    ListPtr temp = S.head;
    while (index <= middle) {
        all[index] = temp->data;
        temp = temp->next;
        index++;
    }
    // 经过中间值后，对每个字符进行判断
    while (index < S.strLen) {
        if (temp->data != all[int(2*middle-index)])
            return false;
        temp = temp->next;
        index++;
    }
    delete []all;
    return true;
}


