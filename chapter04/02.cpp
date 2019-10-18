/* Q4.2 去掉c程序中的注释
 * by TYY
 * created: 2019.10.18
 * last edit: 2019.10.18
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    bool inAnnotation;  // 当前是否处于注释中
    bool inString;      // 当前是否处于字符串中
    string all;         // 用于存储所有代码的变量
    string curLine;     // 用于存储当前行的代码
    /// 对每一行
    while(getline(cin, curLine)) {
        for(int i = 0; i < curLine.length(); ++i) {
            // 如果当前处于注释中
            if (inAnnotation) {
                // 找到注释结尾时
                if (curLine[i] == '*' && i != curLine.length()-1 && curLine[i+1] == '/') {
                    ++i;
                    inAnnotation = false;
                }
                else {
                }
            }
            // 当前不在注释
            else {
                // 找到注释开头
                if (!inString && curLine[i] == '/' && i != curLine.length()-1 && curLine[i+1] == '*') {
                    ++i;
                    inAnnotation = true;
                }
                // 发现转义字符\"
                else if (inString && curLine[i] == '\\' && i != curLine.length()-1 && curLine[i+1] == '"') {
                    all += curLine[i];
                    all += curLine[i+1];
                    ++i;
                }
                else 
                
            }
            
        }
    }

    

    return 0;
}
