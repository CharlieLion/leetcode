#include<iostream>
#include<string.h>
using namespace std;


class Solution {
public:
    int countArrangement(int n) {
        int *arr = new int[n+1]{0};
        // cout<<arr[0]<<arr[1]<<arr[2]<<endl;
        int u = res(n,1, arr);
        delete(arr);
        return u;
    }
    int res(int n, int m, int* &arr)
    {
        int sum =0;
        if(m>n)
        {
            return 1;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(arr[i]==0)
            {
                arr[i] = 1;
                if(i%m==0||m%i==0)
                {
                    sum +=res(n, m+1, arr);
                }
                arr[i]=0;
            }
        }
        return sum;
    }

};

int main()
{
    Solution so;
    cout<<so.countArrangement(3);
    return 0;
}