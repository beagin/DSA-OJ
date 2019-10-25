/* Q4.3 前缀中的周期 
 * by TYY
 * created: 2019.10.20
 * last edit: 2019.10.20
 */

#include <iostream>
#include <string>

using namespace std;

/**Func：获取字符串对应的next数组
 * 
 * 
 */
int* findNext(const string P) {
    int n = P.length();     // 字符串总长度
    int *next = new int[n+1]; // next数组
    int j, k;
    j = 0; k = -1;
    next[0] = -1;
    while (j < n) {
        while (k >= 0 && P[k] != P[j])
            k = next[k];
        ++j;
        ++k;
        next[j] = k;
    }
    
    return next;
}

int main(int argc, char const *argv[])
{
    int n, index=1;
    string curStr;
    while (cin >> n) {
        if (n == 0)
            return 0;
        cin >> curStr;
        cout << "Test case #" << index++ << endl;
        // 获取next数组
        int *next = findNext(curStr);
        // 从前往后判断是否满足循环
        for (int j = 2; j <= n; ++j) {
            if (0 != next[j] && (next[j] % (j-next[j]) == 0)) 
                cout << j << " " << int(j / (j-next[j])) << endl;
        }
        cout << endl;
    }
    return 0;
}
