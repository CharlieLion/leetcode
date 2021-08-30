/*
小团每天都会走过一条路去上课。这条路旁种有丁香树，从左向右排成一排并编号为 1 … n。又是一年一度的丁香季，
所有丁香都开花了，第 i 棵丁香树的芳香值为 ai。

小团要从第一棵丁香树走到最后一棵。当走到第 i 棵丁香树时，
如果这棵丁香树的芳香值比之前经过的 i - 1 棵丁香树中 x 棵的芳香值高，
她的满意度就要加上那 x 棵丁香树的不同的芳香值个数。

小团知道了这 n 棵丁香树的芳香值，
她想知道走过这 n 棵丁香树后自己的满意度是多少。
10
1 1 2 2 2 3 3 3 3 1
样例输出
11

*/

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
    int saified(vector<int>arr)
    {   
        int max=arr[0];
        int tag = arr[0];  //判断上衣状态和目前是否一致
        vector<int> temp(31,0);
        int num=0;
          //当前状态满意值
        int saif = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==tag)
            {
                saif +=num;
            }
            else
            {   
                addnum(temp,arr[i-1]);
                num = bigNum(temp,arr[i]);
                saif +=num;
                tag = arr[i];
            }
        }
        return saif;
    }
    private:
      //num代表N种不同的数值
    void addnum(vector<int>&temp,int n)
    {
        if(temp[n]==0)
        {
            temp[n]=1;
        }
    }
    int bigNum(vector<int>temp, int n)
    {
        int u=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]!=0)
            u++;
        }
        return u;
    }
};
int main()
{
    int n;
    // cin>>n;
    int temp=0;
    // vector<int>arr(n,0);
    vector<int>arr={1,1,2 ,2, 2 ,3 ,3 ,3 ,3 ,1};
    // for(int i=0;in;i++)
    // {
    //     cin>>temp;
    //     arr[i]=temp;
    // }
    //   for(auto item:arr)
    // {
    //     cout<<item;
    // }
    Solution so;
    cout<<so.saified(arr);
  
}