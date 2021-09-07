//寻找素数

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断输入的两个数a,b之间（包含a、b）有多少个素数，其中a<b。
素数，即质数，一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数。
     * @param a int整型 起始自然数
     * @param b int整型 终止自然数
     * @return int整型
     */
    int calculate(int a, int b) {
        // write code here
        int sum=0;
        for(int i=a;i<=b;i++)
        {
            if(i==1) continue;
            int j=2;
            for(;j<=sqrt(i);j++)
            {
                if(i%j==0) break;
            }
            if(j>sqrt(i)) sum++;
        }
        return sum;
    }
};

int main()
{
    Solution so;
    int ans = so.calculate(1,111);
    cout<<ans;
    return 0;
}