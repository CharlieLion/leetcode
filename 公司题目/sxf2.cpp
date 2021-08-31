/*障碍地图， 可以通过为0， 不能通过为1 ，判断从0，0 到n,m点的所有通路方式*/


#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void ans(vector<vector<int>>&map,int n,int m)
    {
        process(map,n,m);
        cout<<map[0][0];
    }
    private:
    void process(vector<vector<int>>&map,int n,int m)
    {
        //最后一行
        bool tag =true;
        for(int i=m-1;i>=0;i--)
        {
            if(map[n-1][i]!=-1&&tag)
            {
                map[n-1][i]=1;
            }
            else
            {
                tag= false;
            }
        }
        tag =true;
        for(int i=n-1;i>=0;i--)
        {
            if(map[i][m-1]!=-1&&tag)
            {
                map[i][m-1]=1;
            }
            else
            {
                tag= false;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(map[i][j]!=-1)
                {
                    map[i][j] = max(map[i+1][j],0)+max(map[i][j+1],0);
                }
            }
        }
    }

};

int main()
{
    int n,m,temp;   //n行m列；
    cin>>n>>m;
    vector<vector<int>>map(n,vector<int>(m));
    for( int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            if(temp==0)
            {
                map[i][j]=temp;
            }
            else
            {
                map[i][j]=-1;
            }
            
        }
    } 
    Solution so;
    so.ans(map,n,m);
    return 0;
}