#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    long dp[51][51][51];

    int _m,_n,_maxMove;
    
    inline long dfs(int x,int y,int s){  //x y 0
        if(s > _maxMove)return 0;
        if(x<0 || x>=_m || y<0 || y>=_n)return 1;
        if(dp[x][y][s] != -1)return dp[x][y][s];
        return dp[x][y][s] = (dfs(x+1,y,s+1)+dfs(x-1,y,s+1)+dfs(x,y+1,s+1)+dfs(x,y-1,s+1))%MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        _m = m;
        _n = n;
        _maxMove = maxMove;
        return dfs(startRow,startColumn,0);
    }
};

int main()
{
    Solution so;
    cout<<so.findPaths(1,3,3,0,1);
    
    return 0;
}
