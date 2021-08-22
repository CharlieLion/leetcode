#include<string>
#include<iostream>

class Solution
{
    public:
    bool checkRecord(std::string s)
    {
        if(""==s) return false;
        int n=s.size();
        int ab=0;
        int la=0;
        bool tag_la=false;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A') 
            {
                ab++;
                if(ab>=2) return false;
                tag_la = false;
                la =0;
            }
            if(s[i]=='L'&&tag_la==false)
            {
                la++;
                tag_la=true;
            }
            else if(tag_la==true&&s[i]!='L')
            {
                tag_la=false;
                la=1;
            } 
            else if(tag_la==true&&s[i]=='L') 
            {
                la++;
                if(la>=3) return false;
            }
            if(s[i]=='P') 
            {
                tag_la=false;
                la=0;
            }
        }
        return true;
    }
};

int main()
{
    Solution so;
    std::cout<<so.checkRecord("LALL")<<std::endl;
}