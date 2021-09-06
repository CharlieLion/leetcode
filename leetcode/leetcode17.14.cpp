#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sortFindsmallestK(arr,k,0,arr.size()-1);
        vector<int> ans=arr;
        ans.resize(k);
        return ans;
    }
private:
    void sortFindsmallestK(vector<int>& arr, int k,int start, int end)   //start and end is the position
    {
        int pa = arr[start];
        int _temp_a = start+1, _temp_b = end;
        while(_temp_a<=_temp_b)
        {
            while(pa<arr[_temp_b]) _temp_b--;
            while(pa>arr[_temp_a]) _temp_a++;
            if(_temp_a<=_temp_b)
            {
                int temp = arr[_temp_b];
                arr[_temp_b] = arr[_temp_a];
                arr[_temp_a] = temp;
            }    
        }
        int temp = arr[_temp_b];
        arr[_temp_b] = pa;
        arr[start] = temp;
        if(_temp_b==k-1)  return;
        else if(_temp_b<k-1) sortFindsmallestK(arr,k,_temp_b+1,end);
        else sortFindsmallestK(arr,k,start,_temp_b-1);


    }
};
int main()
{
    vector<int>arr = {1,3,5,7,2,4,6,8};
    Solution so;
    so.smallestK(arr,4);

}