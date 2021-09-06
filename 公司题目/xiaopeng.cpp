/*
将输入的字符串中的数字部分用括号括起来
456asb-->(456)asb
*/


#include<iostream>
#include<string>
using namespace std;

class Solution
{
    public:
    void ans(string str)
    {
        bool tag = false; //标志是数字模式
        string ans;
        for(int i=0, n = str.size();i<n;i++)
        {
            if(tag==false&&(str[i]<'0'||str[i]>'9'))
            {
                ans += str[i];
            }
            else if(tag==false&&(str[i]>='0'&&str[i]<='9'))
            {
                ans+='(';
                ans+=str[i];
                tag =true;
            }
            else if(tag==true&&(str[i]>='0'&&str[i]<='9'))
            {
                ans+=str[i];
            }
            else if(tag==true&&(str[i]<'0'||str[i]>'9'))
            {
                ans+=')';
                ans+=str[i];
                tag =false;
            }
        }
        if(tag==true)
        {
            ans+=')';
        }
        cout<< ans;
    }
};

int main()
{
    Solution so;
    so.ans("456asd");
    return 0;
}
