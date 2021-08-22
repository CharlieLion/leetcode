#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char tag;
        int sum=0,i=0;   //i是查找指针， sum是长度指针
        while(i<n)
        {
            if(tag != chars[i])
            {
                tag = chars[i];
                int num=0;
                while(i<n&&tag==chars[i])
                {
                    num++;
                    i++;
                }
                chars[sum++]=tag;   //获取新写入位置
                if(num>1)
                {
                    char *p = getnum(num);
                    while(*p!='\0')
                    {
                        chars[sum]=*p;
                        p++;
                        sum++;
                    }
                }
            }       
           
        }
         return sum;
    }
    char* getnum(int num)   //可以用 to_string(int ) 处理
    {
        char* p =new char[5];
        int _max=1000;
        int n=0;
        bool label =false;
        while(_max!=0)
        {
            int tag = num/_max;
            if(tag>0)
            {
                label =true;
                p[n]=char(tag+'0');
                num -=tag*_max;
                n++;
            }
            else if(label)       //若不是第一位为0,则需要保留这个0 例如100
            {
                p[n]='0';
                num -=tag*_max;
                n++;
            }
            _max = _max/10;
        }
        p[n]='\0';
        return p;
    }
};

int main()
{
    Solution so;
    vector<char>ss={'a'};
    cout<<so.compress(ss)<<endl;
    for(auto i:ss)
    {
        cout<<i;
    }
    return 0;
}