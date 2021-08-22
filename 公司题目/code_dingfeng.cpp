#include<iostream>
#include<math.h>
using  namespace  std;

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return int整型
     */
    int getPipCount(int n) {
        // write code here
        if(n<3)  return 1;
        int a, b, sum;
        a= 1;  //幼株
        b=1;  //成猪
        sum = 1;  //总猪
        for(int i =3; i <=n;i++)
        {
            sum = a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
};

int main()
{
    Solution so;
    cout<<so.getPipCount(10);
}