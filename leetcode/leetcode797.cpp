#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int end = graph.size()-1;
        vector<int> temp;
        temp.emplace_back(0);
        getPath(graph,0,end, temp);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void getPath(vector<vector<int>>& graph, int position, int end, vector<int>& temp)
    {
        if(position==end)
        {
            ans.emplace_back(temp);
            return;
        }
        else
        {
            vector<int> _temp = graph[position];
            if(_temp.empty()) return;
            for(auto item: _temp)
            {
                temp.emplace_back(item);
                getPath(graph,item,end,temp);
                temp.pop_back();
            }
        }
    }
};


int main()
{
    vector<vector<int>> map = {vector<int>{1,2},vector<int>{3},vector<int>{3},vector<int>{}};
    Solution so;
    so.allPathsSourceTarget(map);
    cout<<"123"<<endl;

    return 0;
}

