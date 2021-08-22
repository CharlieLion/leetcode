#include<iostream>

class Solution {
public:
    int reverse(int x) {
        long n = 0;   //用长整数存储
        while (x)
        {
            n = n * 10 + x % 10;   //保存
            x /= 10;
        }
        return n > INT_MAX || n < INT_MIN ? 0 : n;   //判断是否超出上届或者下界
    }

};


int main()
{
    Solution so;
    int abc = -2147483648;
    // std::cout<<INT_MAX<<std::endl;
    int ss = so.reverse(abc);
    std::cout<<ss<<std::endl;
    return 0;
}