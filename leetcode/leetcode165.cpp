#include<iostream>
#include<string>
using namespace std;

class Solution
{
    public:
    int compareVersion(string version1, string version2) {
        int a1=0,a2=0;
        bool tag = false;
        for(int i=0,n=version1.size();i<n;i++)
        {
            if(version1[i]>='1'&&version1[i]<='9')
            {
                a1+=version1[i];
                tag =true;

            }
            else if(version1[i]=='0'&&tag)
            {
                a1+=version1[i];
            }
            else if(version1[i]=='.')
            {
                tag = false;
            }
        }
        tag = false;
        for(int i=0,n=version2.size();i<n;i++)
        {
            if(version2[i]>='1'&&version2[i]<='9')
            {
                a2+=version2[i];
                tag =true;

            }
            else if(version2[i]=='0'&&tag)
            {
                a2+=version2[i];
            }
            else if(version2[i]=='.')
            {
                tag = false;
            }
        }
        int u = a1.size()>a2.size()?a1.size():a2.size();
        for(int i=0;i<u;i++)
        {
            if(a1[i]>a2[i]) return 1;
            else if(a1[i]<a2[i]) return -1;
        }
        if(a1.size()==a2.size()) return 0;
        else
        {
            if(a1.size()>a2.size()) return 1;
            else return -1;
        }
    }
};

int main()
{
    string version1 = "1.1", version2 = "1.10";
    Solution so;
    cout<<so.compareVersion(version1,version2);
    return 0;
}