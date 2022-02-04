
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len= rectangles.size();
        for(int i=0;i<len;i++)
        {
            auto tac = rectangles[i];
            int temp = min(tac[0],tac[1]);
            if(maxLen<temp)
            {
                maxLen = temp;
                numMax = 1;
            }
            else if(maxLen==temp)
            {
                numMax += 1;
            }
        }
        return numMax;
    }
private:
    int maxLen=0;
    int numMax=0;
};


int main()
{
    vector<vector<int>> rectangles= {{5,8},{3,9},{5,12},{16,5}};
    Solution so;
    cout<<so.countGoodRectangles(rectangles);
    return 0;

}

