#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size = bits.size();
        int i =0;
        while(i<size)
        {
            if(bits[i]==1)
            {
                i+=2;
            }
            else 
            {
                if(i+1==size) return true;
                else
                {
                    i+=1;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> requet = {1, 0, 0};
    Solution so;
    cout<<so.isOneBitCharacter(requet);
    return 0;
}