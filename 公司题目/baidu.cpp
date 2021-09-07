/*Kimi的英语老师是一个非常有趣的人。每一次考试之前她都会在不经意间透露一下试题的难度，
她会在黑板上写一串长长的字符。你需要从这串字符中按照次序找到E或e、A或a、S或s、Y或y
这四个字母，每四个字母为一组，将构成一个大家熟悉的单词（easy）。每找到一组字母，
即构成一个单词easy则容易等级加1。当然，容易等级越大就意味着考试题目越容易，
所以Kimi希望能够从中找到最多的字母组合。值得注意的是如果有多于一个easy，
每一个easy都需要按照次序出现，也就是说下一个easy中的“e”必须在前一个easy中的“y”之后出现。 
你能否编写一个程序告诉Kimi这次英语考试的容易等级是多少呢？

*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int tag = 0; // tag=1 e  2 ->a 3->s -4>y
    int sum = 0;
    for(int i=0,n=s.size();i<n;i++)
    {
        if(tag ==0 &&(s[i]=='e'||s[i]=='E'))
        {
            tag =1;
        }
        else if(tag==1 &&(s[i]=='a'||s[i]=='A'))
        {
            tag =2;
        }
        else if(tag==2 &&(s[i]=='s'||s[i]=='S'))
        {
            tag =3;
        }
        else if(tag==3 &&(s[i]=='y'||s[i]=='Y'))
        {
            tag =0;
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}