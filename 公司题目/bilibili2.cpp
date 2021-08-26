//给定一个含有多行的一维数组，每行元素都已经严格递增排序好了，请你找到在这些行中同时出现的最小元素。如果找不到元素返回-1
#include<iostream>
#include<vector>
using namespace std;

int getsameSimle(vector<vector<int>>map)
{
    int n=map.size();
    vector<int> pos(n,0);
    int min = map[0][0];
    bool totag = true;
    int i =1;     //第几行的下表
    while(i<n)
    {
        if(totag==false) 
            break;
        while(pos[i]<map[i].size())
        {
            if(map[i][pos[i]]==-1) 
            {
                totag=false;
                break;
            }
            if(min>map[i][pos[i]])
            {
               pos[i]++;
            }
            else if(min<map[i][pos[i]])
            {
                min=map[i][pos[i]];
                i=0;
            }
            else 
            {
                i++;   
                break;
            }
        }
    }
    if(map[0][pos[0]]==-1) return -1;
    return map[0][pos[0]];
}


int main()
{
    vector<vector<int>>map;
    vector<int> arr;
    char var;
    int temp;
    bool tag = false;
    while(1)
    {   
        var = getchar();
        if(var>='0'&&var<='9')
        {
            if(temp==-1) temp=0;
            temp = temp*10 +(var-'0');
            tag =true;
        }
        else 
        {
            if(tag == true)  //判断存在逗号意外的参数
            {
                arr.emplace_back(temp);
                temp = -1;
                tag =false;
            }
            
        }
        if(var=='\n'&&arr.empty()) break;
        if(var=='\n'&&!arr.empty())
        {
            arr.emplace_back(temp);
            map.emplace_back(arr);
            arr.clear();
            temp = -1;
            tag = false;
        } 
    }
    cout<<getsameSimle(map);
    return 0;
}