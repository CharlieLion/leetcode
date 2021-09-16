#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
     vector<int> minimumNumber(vector<int>& target) {
         int n = target.size();
         vector<int> ans(n,0);
         for(int i=0;i<n;i++)
         {
             ans[i] = findN(target[i]);
         }
         return ans;
     }

    private:
    int findN(int u)
    {
        if(u<10) return -1;
        else if(u==10)  return 4;
        int sum =4;
        u = u-10;
        while(u>=4)
        {
            u = u-4;
            sum++;
        }
        if(u!=0)  sum++;
        return sum;

    }
};

int main()
{
    vector<int> m={10,16,6,66,99,963};
    Solution so;
    vector<int> ans = so.minimumNumber(m);
    return 0;
}