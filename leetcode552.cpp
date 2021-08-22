/*
可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
'A'：Absent，缺勤
'L'：Late，迟到
'P'：Present，到场
如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：

按 总出勤 计，学生缺勤（'A'）严格 少于两天。
学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 109 + 7 取余 的结果。

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        int sum=0;
        vector<vector<vector<int>>> map(2,vector<vector<int>>(3,vector<int>(n+1,0)));
        sum = findNum(n,0,0,map);
        return sum;
    }
private:
#define MAX 1000000007
    int findNum(int n, int a, int l,vector<vector<vector<int>>> &map)
    {
        if(n==0) 
        {
            return 1;
        }
        if(map[a][l][n]!=0)
        {
            return map[a][l][n];
        }
        int sum=0;
        if(a==0)
        {
            sum = (sum + findNum(n-1, 1, 0, map))%MAX;
        }
        if(l<2)
        {
            sum = (sum + findNum(n-1, a, l+1, map))%MAX;
        }

        sum = (sum+ findNum(n-1, a, 0,map))%MAX;

        map[a][l][n] = sum;
        return sum;
    }
};

int main()
{
    Solution so;
    cout<<so.checkRecord(10101)<<endl;
    return 0;
}