/*不重复字符
时间限制： 1000MS
内存限制： 65536KB
题目描述：
给定一个字符串，找到第一个不重复的字符，并返回该字符的索引。如果不存在，则返回-1。

假定该字符串只包含小写字母。



输入描述
footballgamefinal

输出描述
3*/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int cha[256];
    for(int i=0,n=s.size();i<n;i++)
    {
        cha[int(s[i])]++;
    }
    int u=0;
    for(int n=s.size();u<n;u++)
    {
        if(cha[int(s[u])]==1) 
        {
            cout<<u<<endl; 
            break;
        }
    }
    if(u==s.size()) cout<<-1<<endl;
    return 0;

}