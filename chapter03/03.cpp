/**Q3.3 栈的基本操作
 * by TYY
 * 2019.10.13
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    // 对每一组数据
    for (int i = 0; i < m; ++i) {
        int n;
        vector<int> myStack;
        bool error = false;
        cin >> n;
        // 对每一个操作
        for (int j = 0; j < n; ++j) {
            string operation;
            cin >> operation;
            if ("push" == operation) {
                int curNum;
                cin >> curNum;
                myStack.push_back(curNum);
            }
            else {
                if (myStack.size() > 0)
                    myStack.pop_back();
                else {
                    error = true;
                }
            }
        }
        // output
        if (error)
            cout << "error" << endl;
        else {
            if (myStack.size() > 0) {
                for (int k = 0; k < myStack.size() - 1; ++k) {
                    cout << myStack[k] << " ";
                }
                cout << myStack[myStack.size() - 1] << endl;
            }
        }
    }
    return 0;
}