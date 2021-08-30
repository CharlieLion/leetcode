#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return int整型
     */

    bool isBig(string s, int pos, string ans)
    {
        for(int i=1;i<ans.size();i++)
        {
            if(s[i+pos]<ans[i]) return false;
        }
        return true;
    }
    int maxValue(string s, int k) {
        // write code here
        int temp;
        string ans;
        temp = s[0]-'0';
        int tag = 0;
        for(int i=1;i<s.size()-k+1;i++)
        {
            if(tag>i) continue;
            if(temp<(s[i]-'0'))
            {
                tag = i;
                temp = s[i]-'0';
            }
        }
        for(int i=tag;i<tag+k;i++)
        {
            ans +=s[i];
        }
        for(int i= tag+1;i<s.size()-k+1;i++)
        {
            if(s[i]==ans[0])
            {
                if(isBig(s,i, ans))
                {
                    ans = "";
                    for(int j=0;j<k;j++)
                    {
                        ans +=s[j+i];
                    }
                }
            }
        }
        temp = 0;
        for(int i=0;i<ans.size();i++)
        {
            temp *=10;
            temp+=ans[i]-'0';
        }
        return temp;
    }
};

int main()
{
    string s = "12386998";
    Solution so;
    cout<<so.maxValue(s,3);
    return 0;
}