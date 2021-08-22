#include<iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        // auto isVowel = [vowels = "aeiouAEIOU"s](char ch) 
        // {
        //     return vowels.find(ch) != string::npos;
        // };
        int n = s.length();
        int i=0,j = n-1;
        while(i<j)
        {
            while(i<j&&!isAEIOU(s[i])) i++;
            while(i<j&&!isAEIOU(s[j])) j--;
            char temp = s[i];
            s[i] =s[j];
            s[j] =temp;
            i++;
            j--;
        }
        return s;
    }
private:
    inline bool isAEIOU(char c)
    {
        return (c=='a'||c=='e'||c=='o'||c=='i'||c=='u'||c=='A'||c=='E'||c=='O'||c=='I'||c=='U');
    }

};

int main()
{
    Solution so;
    cout<<so.reverseVowels("aA");
    return 0;
}