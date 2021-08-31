/*
Bob在玩一个网络游戏，在一次活动中，他们需要挑战五个boss，每个人对每个boss都会造成一定的伤害，并且每个boss都有一个分数系数，比如一个人造成了100点伤害，分数系数是10，那么最后的得分就是1000点。

现在Bob在活动结束后得到了每个人对五个boss分别造成了多少伤害，现在Bob想知道最高的得分是多少，以及有多少个人的分数和最高得分一样，并且从小到大输出这些人的编号。(编号从1到n)
第一行五个整数a, b, c, d, e分别表示分数系数(1≤a,b,c,d,e≤10)。

第二行一个整数n表示参加活动的人数(1≤n≤1e5)。

接下来n行，每行五个整数x分别表示对五个boss造成的伤害(0≤x≤1e5)。

输出描述
第一行一个整数x表示最高得分。

第二行一个整数k表示最高得分的人数。

接下来k行每行一个整数表示获得最高得分的人的编号

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void ans(vector<int> radio,vector<vector<int>>score)
    {
        int n= score.size();
        int max=0;
        vector<int> sum(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                sum[i]+=radio[j]*score[i][j];
            }
            if(max<sum[i])
            {
                max = sum[i];
            }
        }
        int num = 0;
        vector<int>sort;
        for(int i=0;i<n;i++)
        {
            if(sum[i]==max)
            {
                num++;
                sort.emplace_back(i);
            }
        }
        cout<<max<<endl;
        cout<<num<<endl;
        for(int i=0;i<num;i++)
        {
            cout<<sort[i]+1<<endl;
        }
    }
};

int main()
{
    vector<int> radio(5,0);
    int n,temp;
    vector<vector<int>>score;
    for(int i=0;i<5;i++)
    {
        cin>>temp;
        radio[i]=temp;
    }
    cin>>n;
    vector<int>_temp(5);
    for(int i=0;i<n;i++)
    {
        // _temp.clear();1 1 
        for(int j=0;j<5;j++)
        {
            cin>>temp;
            _temp[j]=temp;
        }
        score.emplace_back(_temp);
    }
    Solution so;
    so.ans(radio,score);
    return 0;
}