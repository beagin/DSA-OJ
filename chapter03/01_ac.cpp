#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#define MAXSIZE 610
#define IS_NUM(ch) (ch >= '0' && ch <= '9')
#define IS_OP(ch) (ch == '+' || ch == '-' || ch == '*' || ch == '/')

string str;
stack<char> op;
stack<int> cal;
vector<string> post;

int prior(char ch)
{
    if (ch == '+' || ch == '-')
        return 0;
    else
        return 1;
}

void post_add(char tchar)
{
    char tmp[2];
    tmp[0] = tchar;
    tmp[1] = '\0';
    string s_tmp(tmp);
    post.push_back(s_tmp);
}

void make_post()
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch == '(')
            op.push(ch);
        else if (ch == ')')
        {
            while (!op.empty())
            {
                char c = op.top();
                op.pop();
                if (c == '(')
                    break;
                post_add(c);
            }
        }
        else if (IS_OP(ch))
        {
            if (!op.empty())
            {
                char tchar = op.top();
                while (tchar != '(' && prior(tchar) >= prior(ch))
                {
                    op.pop();
                    post_add(tchar);
                    if (!op.empty())
                        tchar = op.top();
                    else
                        break;
                }
            }
            op.push(ch);
        }
        else
        {
            int &pos = i;
            char tmp[MAXSIZE];
            int ptr = 0;
            while (IS_NUM(str[pos]))
                tmp[ptr++] = str[pos++];
            pos--;
            tmp[ptr] = '\0';
            string s_tmp(tmp);
            post.push_back(s_tmp);
        }
    }
    while (!op.empty())
    {
        char tchar = op.top();
        op.pop();
        post_add(tchar);
    }
    return;
}

void calculate()
{
    int size = post.size();
    for (int iter = 0; iter < size; iter++)
    {
        string &s = post[iter];
        if (IS_NUM(s[0]))
            cal.push(atoi(s.c_str()));
        else
        {
            int b = cal.top();
            cal.pop();
            int a = cal.top();
            cal.pop();
            int c;
            char ch = s[0];
            switch (ch)
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = a / b;
                break;
            }
            cal.push(c);
        }
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        str.clear();
        post.clear();
        cin >> str;
        make_post();
        calculate();
        int res = cal.top();
        cal.pop();
        cout << res << endl;
    }
    return 0;
}