#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<int>> ans(x, vector<int>(y));
        for(int j = 0;j < y;j++)
        {
            if(j==0)
            {
                ans[0][j] = grid[0][j];
            }
            else{
                ans[0][j] = ans[0][j-1]+grid[0][j];
            }
        }
        for(int i=1;i<x;i++)
        {
            
            for(int j = 0;j < y;j++)
            {
                if(j==0)
                {
                    ans[i][j] = ans[i-1][j] + grid[i][j];
                }
                else
                {
                    ans[i][j] =min(ans[i-1][j],ans[i][j-1])+ grid[i][j];
                }
            }
        }
        int tt = ans[x-1][y-1];
        return tt;
    }
};

int main()
{
    vector<vector<int>> uk = {vector<int>{1,2,3},vector<int>{4,5,6}};
    Solution so;
    int sum = so.minPathSum(uk);
    cout<<sum<<endl;
    
}