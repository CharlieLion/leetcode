/*判断括号有效性*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 括号字符串
     * @return bool布尔型
     */
    bool isValid(string str) {
        // write code here
        stack<char> st;
        for(int i=0,n=str.size();i<n;i++)
        {
            if(str[i]=='{'||str[i]=='['||str[i]=='(')
            {
                st.push(str[i]);
            }
            else
            {
                if(str[i]=='}')
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }
                    else return false;
                }
                else if(str[i]==']')
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else return false;
                }
                else if(str[i]==')')
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    string ans= "{}[((]))";
    Solution so;
    bool t = so.isValid(ans);
    cout <<t<<endl;
    return 0;
}