/* Q3.2 滑动窗口
 * by TYY
 * 2019.10.11
 * 
 */

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    /// 接受输入
    int n, k;
    scanf("%d %d", &n, &k);
    int *allNum = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &allNum[i]);
    /// 相关变量
    deque<int> maxQueue, minQueue, maxIndex, minIndex;
    /// 前k-1个数入队列
    for (int i = 0; i < k-1; ++i) {
        while (maxQueue.size() > 0 && maxQueue.back() <= allNum[i]) {
            maxQueue.pop_back();
            maxIndex.pop_back();
        }
        maxQueue.push_back(allNum[i]);
        maxIndex.push_back(i);
        while (minQueue.size() > 0 && minQueue.back() >= allNum[i]) {
            minQueue.pop_back();
            minIndex.pop_back();
        }
        minQueue.push_back(allNum[i]);
        minIndex.push_back(i);
    }
    /// 对其后数字进行判断
    /// minQueue
    for (int i = k-1; i < n; ++i) {
        while (minQueue.size() > 0 && minQueue.back() >= allNum[i]) {
            minQueue.pop_back();
            minIndex.pop_back();
        }
        while (minQueue.size() > 0 && minIndex[0] < i-k+1) {
            minQueue.erase(minQueue.begin());
            minIndex.erase(minIndex.begin());
        }
        minQueue.push_back(allNum[i]);
        minIndex.push_back(i);
        printf("%d", minQueue[0]);
        if (i != n-1)
            printf(" ");
    }
    printf("\n");
    /// maxQueue
    for (int i = k-1; i < n; ++i) {
        while (maxQueue.size() > 0 && maxQueue.back() <= allNum[i]) {
            maxQueue.pop_back();
            maxIndex.pop_back();
        }
        while (maxQueue.size() > 0 && maxIndex[0] < i-k+1) {
            maxQueue.erase(maxQueue.begin());
            maxIndex.erase(maxIndex.begin());
        }
        maxQueue.push_back(allNum[i]);
        maxIndex.push_back(i);
        printf("%d", maxQueue[0]);
        if (i != n-1)
            printf(" ");
    }
    delete []allNum;
    return 0;
}
