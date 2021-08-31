/*厨师做菜， LRU问题， 桌子上最大摆放3套餐具，1~6为不同菜，需要不同餐具，7为终止符号，每一道菜需要15分钟，更换餐具6分钟*/

#include<iostream>
#include<vector>
using namespace std;


class Solution
{
    public:
        void sum(vector<int>arr)
        {
            int _sum = 0;
            vector<int>table(3,0);
            for(int i=0;i<arr.size();i++)
            {
                _sum += isExchange(arr[i],table);
                _sum += 15;
            }
            cout<<_sum-18;
        }
    private:
        
        int isExchange(int num,vector<int>&table)
        {
            for(int i=0;i<3;i++)
            {
                if(table[i]==num)
                {
                    if(0==i)
                    {
                        return 0;
                    }
                    else if(1==i)
                    {
                        int temp = table[0];
                        table[0] = num;
                        table[1] = temp;
                        return 0;
                    }
                    else if(2==i)
                    {
                        int temp1=table[0];
                        int temp2 = table[1];
                        table[0]=num;
                        table[1]=temp1;
                        table[2]=temp2;
                        return 0;
                    }
                } // 不在列表中
            }
            int temp1=table[0];
            int temp2 = table[1];
            table[0]=num;
            table[1]=temp1;
            table[2]=temp2;
            return 6;   
        }
};

int main()
{
    int temp;
    vector<int>arr;
    while(1)
    {
        cin>>temp;
        if(temp==7)
            break;
        arr.emplace_back(temp);
    }
    Solution so;
    so.sum(arr);
    return 0;
}