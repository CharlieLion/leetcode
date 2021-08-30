#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        number = 0;
    }
    
    void addNum(int num) {
        arr.emplace_back(num);
        number++;
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        if(number%2==0)
        {
            return (arr[number/2-1]+arr[number/2])/2.0;
        }
        else
        {
            return arr[number/2];
        }
    }
private:
    vector<int>arr;
    int number;
};


int main()
{
    MedianFinder md;
    vector<int> arr={1,2,3,4,5,6};
    for(auto item: arr)
    {
        md.addNum(item);
    }
    cout<<md.findMedian();
}