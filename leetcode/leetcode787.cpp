/*
有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 toi 抵达 pricei。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>map (n, vector<int>(n,-1));
        for(auto item: flights)
        {
            int _src= item[0];
            int _dst= item[1];
            int cost = item[2];
            map[_src][_dst] = cost;
        }
        // for(int i = n-2;i>=0;i--)
        // {
        //     for(int j=n-1;j>i;j--)
        //     {
        //         if(map[i+1][j]!=0&&map[i][j-1]!=0)
        //         {
        //             map[i][j] = min(map[i][j], map[i+1][j]+map[i][j-1]);
        //         }
        //     }
        // }
        return mincost(map,k,src,dst);
       
    }
    int mincost(vector<vector<int>>map,int k,int _src, int _dst)
    {
        int cost = map[_src][_dst];
        if(k>0)
        {
            for(int i=_src+1;i<_dst;i++)
            {
                cost = min(map[_src][i]+mincost(map,k-1,i,_dst),cost);
            }
        }
        return cost;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>>map = {vector<int>{0,1,100},vector<int>{1,2,100},vector<int>{0,2,500}};
    int src = 0;
    int dst = 2;
    int k=1;
    Solution so;
    cout<<so.findCheapestPrice(n,map,src,dst,k);
}