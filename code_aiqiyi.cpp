#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n<0||m<0) return 1;
    int *p = new int[n]{0};
    int *q = new int[m]{0}; 
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
    }
    int maxtime = p[n-1];
    int temp1 =0,temp2=0;
    for(int i=1;i<=maxtime;i++)   //当前时间
    {
        if(i==p[temp1])
            {
                temp1++;
            }
        else
            {
                while(q[temp2]<=i)
                    {
                        cout<<i<<endl;
                        temp2++;
                    }
            }
    }
    while(temp2<m)
        {
            cout<<maxtime+1<<endl;
            temp2++;
        }
    
    delete p,q;
    return 0;
}