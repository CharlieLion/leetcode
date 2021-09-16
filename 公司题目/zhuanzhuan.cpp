#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr ={7,2,3,4,5,6,1};
    if(arr.size()<1) return 1; 
    int first_max=max(arr[0],arr[1]);
    int second_max=min(arr[0],arr[1]);
    for(int i=2,n=arr.size();i<n;i++)
    {
        if(arr[i]>first_max)
        {
        
            first_max = arr[i];
        }
        if(arr[i]>second_max&&arr[i]!=first_max)
        {
            second_max = arr[i];
        }
    }
    cout<<first_max<<"   "<<second_max<<endl;
    return 0;
}