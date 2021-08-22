#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>map(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            map[i][n-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            map[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                map[i][j]=map[i+1][j]+map[i][j+1];
            }
        }

        return map[0][0];
    }
};

int main()
{
    Solution so;
    cout<<so.uniquePaths(3,7);
}