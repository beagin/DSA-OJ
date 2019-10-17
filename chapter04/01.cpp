/* Q4.1 合格的字符串
 * by TYY
 * 2019.10.17
 * last edit: 2019.10.17
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string homeworks[50];
    string pattern, pattern_;
    /// 接受输入
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> homeworks[i];
    }
    cin >> pattern_;
    transform(pattern_.begin(), pattern_.end(), back_inserter(pattern), ::toupper);

    /// 获取需检查的模式
    int index_left, index_right;
    index_left = pattern.find('[');
    index_right = pattern.find(']');
    string check = pattern.substr(index_left+1, index_right-index_left-1);
    /// 将pattern转化为与待匹配串等长的形式
    pattern = pattern.substr(0, index_left) + "0" + pattern.substr(index_right+1);
    
    /// 对每个字符串进行检查
    for (int i = 0; i < n; ++i) {
        bool flag = false;  // 是否匹配
        // 串长度不等则直接不匹配
        if (homeworks[i].length() != pattern.length())
            continue;
        // 将当前串转化为大写
        string temp;
        transform(homeworks[i].begin(), homeworks[i].end(), back_inserter(temp), ::toupper);
        // 判断每个字符
        for (int j = 0; j < temp.length(); ++j) {
            // 方括号外
            if (j < index_left || j > index_right) {
                if (temp[j] != pattern[j])
                    break;
            }
            // 方括号内
            else {
                if (check.find(temp[j]) == check.npos)
                    break;
            }
            if (j == temp.length()-1)
                flag = true;
        }
        // 匹配则输出
        if (flag)
            cout << i+1 << " " << homeworks[i] << endl;
    }

    return 0;
}
