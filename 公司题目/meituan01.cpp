/*
小团最近在玩手机上的四川麻将。四川麻将的一种玩法是玩家摸完牌之后选择三张花色一样的牌按某种顺序换给其他人。为了尽可能破坏对手的游戏体验，小团每次都会选择不连续的三张牌换出去。比如小团手上有14568这5张条子，则他可能会选择158这三张条子换出去。爱思考的小团马上对这个问题进行了推广。

小团把这个问题进行了简化，现在他给了你一个可重集合，并希望你从中选出一个尽可能大的子集使得其中没有两个数是“连续”的（连续是指即这两个数之差的绝对值不超过1）。*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
    public:
    int findNum(vector<int> nums, int n)
    {
    
        int sum = 1;
        sort(nums.begin(),nums.end());
        int temp= nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i]-temp>1)
            {
                temp =nums[i];
                sum++;
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0; i<n;i++)
    {
        cin>>nums[i];
    }
    Solution so;
    cout<<so.findNum(nums, n)<<endl;
    return 0;
}