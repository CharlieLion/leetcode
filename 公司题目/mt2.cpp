#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


bool judge(string str,int left,int right){
    int size = str.size();
    
    while(left>=0 && right<size){
        
        if(str[left] == str[right]){
            if(right == size -1){
                return true;
            }
            left--;
            right++;
        }
        else{
            break;
        }
    }
    return false;
    
    
}

int solution(string str){
    int maxLength = 0;
    int ans = 0;
    int length =0;
    for(int i =str.size()-1;i>=0;i--){
        if(judge(str,i,i)){
            length = (str.size()-1 -i)  * 2 +1;
            maxLength = max(maxLength, length );
        }
        if(judge(str,i-1,i)){
            length = (str.size()-1 -i + 1) * 2;
            maxLength = max(maxLength,length);
        }
    }
    ans = str.size() - maxLength;
    
    
    return ans;
}

int main()
{
    while(1)
    {
        string str;
        int ans;
        cin>>str;

        ans = solution(str);
        cout<<ans<<endl;
    }
    
    return 0;
}