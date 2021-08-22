#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        for(int i=0;i<s.size();i++)
        {
            int l1 = getLength(s,i,i)-1;
            int l2 = getLength(s,i,i+1);
            temp = max(l1,l2);
            if(maxLength<temp)
            {
                start = i-(temp-1)/2;
                maxLength = temp;
            }
        }
        return s.substr(start, maxLength);
        
    }
    int getLength(string s, int i,int j)
    {
        if(j>=s.size()) return 0;
        int length = 0;
        while(i>=0&&j<s.size()&&s[i]==s[j])
        {
            length+=2;
            i--;
            j++;
        }
        return length;
    }
private:
    int start = 0;
    int maxLength = 0;
    int temp;
};

int main()
{
    Solution so;
    string p =so.longestPalindrome("tattarrattat");
    cout<< p<<endl;

}