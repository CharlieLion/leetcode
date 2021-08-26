#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int sum=0;
        int i=0,j = people.size()-1;
        while(i<=j)
        {
            if(people[i]+people[j]>limit)
            {
                j--; sum+=1;
            }
            else
            {
                i++;j--;
                sum+=1;
            }
        }
        return sum;
    }
};

int main()
{
    string str;
    int n = 5;
    vector<int>map={3,5,3,4};
    Solution so;
    cout<<so.numRescueBoats(map,n);
    return 0;
}