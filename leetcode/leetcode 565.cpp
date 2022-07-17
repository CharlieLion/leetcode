#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int findMaxLengthNuminArr(vector<int>&arr,vector<int>& maxNumArr, int index)
    {
        
        if(maxNumArr[index]==0 && arr[index] != -1)    //或者为0， 或者为最后一个节点，无法寻找下一个点
        {
            int temp = arr[index];
            arr[index] = -1;
            maxNumArr[index]= findMaxLengthNuminArr(arr, maxNumArr, temp) +1;
            arr[index] = temp;
        }
        else  //存在的话直接返回保存的数据
        {
            return maxNumArr[index];
        }
        return maxNumArr[index];
    }


public:
    int arrayNesting(vector<int>& arr) {
        vector<int>maxNumArr(arr.size(),0);
        for(int i = 0, n = arr.size(); i<n ; i++)
        {
            findMaxLengthNuminArr(arr,maxNumArr,i);
        }
        
        int maxLength = INT_MIN;
        for(auto item:maxNumArr)
        {
            maxLength = maxLength>item?maxLength:item;
        }

        return maxLength;

    }

};

int main()
{

    Solution so;
    vector<int> arr = {5,4,0,3,1,6,2};
    int maxNum = so.arrayNesting(arr);
    cout<<maxNum;
    return 0;

}