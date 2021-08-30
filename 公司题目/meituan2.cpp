/*
小美在整理她的书。

她有 n 本书要放，书架上也有 n 个位置可以放书。每本书都有一个厚度 ai，可以放书的每个位置都有一个宽度 bj。

小美不想让书折坏，因此只有在满足 ai ≤ bj 的情况下，第 i 本书才可以放到第 j 个位置，否则不可以放。

小美想知道有多少种放书的方案。

样例输入
4
1 2 3 4
2 4 3 4
样例输出
8
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int method(vector<int>&book, vector<int>&space)
    {
        sort(book.begin(),book.end());
        sort(space.begin(),space.end());
        totalNum(book,space,0);
        return num;
    }
    void totalNum(vector<int>&book, vector<int>&space,int n)  //n代表第i本是否能放入
    {
        int _num = book.size();
        if(n==_num)
        {
            num = (num+1)%max;
            return;
        }
        
        for(int j=0;j<_num;j++)
        {
            if(space[j]!=-1&&n>0&&book[n]>space[j])
            {
                tag = true;
                return;
            } 
            if(space[j]!=-1&&book[n]<=space[j])
            {
                int temp = space[j];
                space[j]=-1;
                totalNum(book,space,n+1);
                space[j] = temp;
            }
        }
    }
private:
int max = 1000000007;
int num=0;
bool tag = false;
};


int main()
{
    // int n;
    // cin>>n;
    int temp;
    // vector<int>book(n,0);
    // vector<int>space(n,0);
    // for(int i=0;i<n;i++)
    // {
    //     cin>>temp;
    //     book[i]=temp;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     cin>>temp;
    //     space[i]=temp;
    // }
    
    vector<int>book={1,2,3,4};
    vector<int>space={2,4,3,4};
    Solution so;
    cout<<so.method(book,space);


}