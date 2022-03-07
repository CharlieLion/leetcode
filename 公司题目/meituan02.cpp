/*
最大子段和是一个经典问题，即对于一个数组找出其和最大的子数组。

现在允许你在求解该问题之前翻转这个数组的连续一段（如翻转{1,2,3,4,5,6}的第三个到第五个元素组成的子数组得到的是{1,2,5,4,3,6}），则翻转后该数组的最大子段和最大能达到多少？*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
    private:
    int maxSubarray(vector<int>& arr)
    {
        int pre =0, premax = arr[0];
        for(int i=0,n=arr.size();i<n;i++)
        {
            pre = max(pre+arr[i],arr[i]);
            premax = max(pre,premax);
        }
        return premax;
    }
    public:
    int maxReverseArr(vector<int>&arr)
    {
        int n =arr.size();
        int summax = INT_MIN;
        int tempmax=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                reverse(arr.begin()+i,arr.begin()+j);
                tempmax =  maxSubarray(arr);
                summax = max(summax, tempmax);
                reverse(arr.begin()+i,arr.begin()+j);
            }
        }
        return summax;
    }
};

int main()
{
    Solution so;
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<so.maxReverseArr(arr)<<endl;
    return 0;
}