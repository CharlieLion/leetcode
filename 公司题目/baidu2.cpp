/*X星理工大学新学期开学典礼正在X星理工大学体育馆隆重举行，小小X作为新生代表坐上了主席台。 
在无比骄傲的同时，看到下面坐着的黑压压的人群，小小X想到了这么一个问题： 作为一所理工大学，
女生真的很少。俗话说，红花还需绿叶衬。假设所有参加开学典礼的同学坐成一个 m 行 n 列的矩阵，
其中男生用“M”表示，女生用“F”表示。如果一个女生的旁边8个方位（前、后、左、右以及左前、右前
、左后、右后）坐着另外一个女生，那么她们属于“同一朵红花”。 现在给出一个用于表示男生和女生
就坐情况的字符矩阵，请编写一个程序统计在该字符矩阵中一共有多少朵“红花”？

*/

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
        void findFlowers(vector<vector<int>>&map,int n,int m)
        {
            int d = map.size();
            int r = map[1].size();
            map[n][m]=0;
            if(n+1<d&&map[n+1][m]==1) findFlowers(map,n+1,m); //下搜索
            if(m+1<r&&map[n][m+1]==1) findFlowers(map,n,m+1);
            if(n-1>=0&&map[n-1][m]==1) findFlowers(map,n-1,m);
            if(m-1>=0&&map[n][m-1]==1) findFlowers(map,n,m-1);
        }
        void totalSum(vector<vector<int>>&map)
        {
            int d = map.size();
            int r = map[1].size();
            int sum = 0;
            for(int i=0;i<d;i++)
            {
                for(int j=0;j<r;j++)
                {
                    if(map[i][j]==1)
                    {
                        findFlowers(map,i,j);
                        sum++;
                    }
                }
            }
            cout<<sum<<endl;
        }
};
int main()
{
    int n,m;
    cin>>n>>m;
    char temp;
    vector<vector<int>>map(n,vector<int>(m));    //n为行,m为列
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>temp;
            if(temp=='M')
            {
                map[i][j]=0;
            }
            else
                map[i][j]=1;
        }
    }
    Solution so;
    so.totalSum(map);

    return 0;
}