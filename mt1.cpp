#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>pos(n);
    vector<int>dir(n);
    vector<bool>state(n,0);
    vector<int>time(n,-1);
    int l=0;
    for(int i=0;i<n;i++)
    {
        int pos_;
        char dir_;
        cin>>pos_>>dir_;
        pos[i] = pos_;
        dir[i] = dir_=='L'?0:1;
        if(dir[i]==0) l++;
    }
    int res = n;
    int t=1;
    while(res!=l&&l!=0)
    {
        for(int i=0;i<n;i++)
        {
            
        }
    }
}