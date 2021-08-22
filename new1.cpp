#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> res(n);
    vector<int> temp(n);
    int tem;
    for(int i=0;i<n;i++)
    {
        cin>>tem;
        res[i] = tem;
        if(i>0)
        {
            temp[i] = temp[i-1]+tem;
        }
    }
    int max=0;
    int tag=0;
    for(int i=1;i<n-1;i++)
    {
        if(max<temp[i]*(temp[n-1]-temp[i]))
        {
            max= temp[i]*(temp[n-1]-temp[i]);
            tag = i;
        }
    }
    tag+=1;
    cout<<tag<<endl;
    return 0;
}