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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //dp[i][k]表示从src至多经过k站到达i的最少费用
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        //初始化 src 到 src的费用为0
        for (int k = 0; k <= K + 1; ++k){
            dp[src][k] = 0;
        }
        //开始动态规划
        for (int k = 1; k <= K + 1; ++k){
            for (auto &flight : flights){
                //如果从src至多经过k - 1站可达flight[0]
                if (dp[flight[0]][k - 1] != INT_MAX){
                    //更新从src至多经过k站到达flight[1]
                    dp[flight[1]][k] = min(dp[flight[1]][k], dp[flight[0]][k - 1] + flight[2]);
                }
            }
        }
        return dp[dst][K+1] == INT_MAX ? -1 : dp[dst][K+1];
    }
};
int main()
{
    int n = 5;
    //5 [[1,2,10],[2,0,7],[1,3,8],[4,0,10],[3,4,2],[4,2,10],[0,3,3],[3,1,6],[2,4,5]]
    vector<vector<int>>map = {vector<int>{1,2,10},vector<int>{2,0,7},vector<int>{1,3,8},
    vector<int>{4,0,10},vector<int>{3,4,2},vector<int>{4,2,10},vector<int>{0,3,3},
    vector<int>{3,1,6},vector<int>{2,4,5}
    };
    int src = 0;
    int dst = 4;
    int k=1;
    Solution so;
    cout<<so.findCheapestPrice(n,map,src,dst,k);
}