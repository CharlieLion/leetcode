/*
小明将进行q次旅行。她在一张节点数为n的无向无环联通图上进行旅行，每一次旅行将选择一个起点和一个终点，并从起点开始沿着最短路径向终点行进。她对一次旅途的回忆仅仅只有旅途上途径的最不舒适的一条边。最近她失忆了，请帮她重构回忆。

形式化地，这张图上每条边的长度都为1，每条边均有一个不舒适度 ai，请为每次旅行找出途径的最大的ai 的值。

输入描述
第一行三个以空格隔开的正整数n、m和q，代表图的节点数，边数，以及询问次数。

接下来m行，每行三个以空格隔开的整数ui, vi , ai，分别代表该边相连的两个节点，这条边的不舒适度。保证没有重边和自环。

接下来q行，每行两个以空格隔开的整数xi , yi ，分别表示起点和终点。

2≤n,m,q≤3000，1≤ui,vi,xi,yi≤n，|ai|≤109

输出描述
输出q行，每行一个整数表示对应的答案，即旅途中经过的边的最大不舒适度。如果一条边都没经过，那么输出0

样例输入
5 4 3
1 2 1
2 3 2
3 4 1
4 5 6
1 2
1 5
2 4
样例输出
1
6
2

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void ans(vector<vector<int>>&map,vector<vector<int>>&quest)
    {
        process(map);
        for(int i=0;i<quest.size();i++)
        {
            int a1 = quest[i][0];
            int a2 = quest[i][1];
            if(a1>a2)
            {
                cout<<map[a2][a1]<<endl;
            }
            else{
                cout<<map[a1][a2]<<endl;
            }
        }
    }
    private:
    void process(vector<vector<int>>&map)   //弗洛伊德图
    {
        int n = map.size();
        for(int i =1;i<n;i++) //行
        {
            for(int j=1;j<n;j++)
            {
                for(int u=1;u<n;u++)
                {
                    if(map[i][u]!=-1&&map[u][j]!=-1)
                    {
                        int temp = max(map[i][u],map[u][j]);
                        map[i][j] = max(map[i][j],temp);
                    }
                }
            }
        }
    }

};

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int a1,a2,ad;
    vector<vector<int>>map(n+1,vector<int>(n+1,-1));
    for(int i=0;i<m;i++)
    {
        cin>>a1>>a2>>ad;
        map[a1][a2] = ad;
        map[a2][a1] = ad;
    }
    vector<vector<int>>quest(q,vector<int>(2));
    for(int i=0;i<q;i++)
    {
        cin>>a1>>a2;
        quest[i][0]=a1;
        quest[i][1]=a2;
    }

    Solution so;
    so.ans(map,quest);
    return 0;
}