#include<iostream>
#include<vector>
using namespace std;

void printGrid(vector<vector<int>>grid)
{
    for(auto item: grid)
    {
        for(auto iitem:item)
        {
            cout<<iitem;
        }
        cout<<endl;
    }
}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        y_len = grid.size();
        x_len = grid[0].size();
        int sum = 0;
        for(int i = 0; i<x_len;i++)
        {
            if(grid[0][i]==1)
            {
                turnOffland(grid, i, 0);
                cout<<endl;
                printGrid(grid);
            }
            if(grid[y_len-1][i]==1)
            {
                turnOffland(grid, i, y_len-1);
                cout<<endl;
                printGrid(grid);
            }
        }
        for(int i = 1; i<y_len-1; i++)
        {
            if(grid[i][0]==1)
            {
                turnOffland(grid, 0, i);
                cout<<endl;
                printGrid(grid);
            }
            if(grid[i][x_len-1]==1)
            {
                turnOffland(grid, x_len-1, i);
                cout<<endl;
                printGrid(grid);
            }
        }
        for(int i = 0; i <y_len; i++)
        {
            for(int j=0;j<x_len;j++)
            {
                sum += grid[i][j];
            }
        }
    return sum;
    }
private:
    void turnOffland(vector<vector<int>>& grid, int x, int y) // 外y 内x
    {
        grid[y][x] = 0;
        if(y>0&& grid[y-1][x]==1)
        {
            turnOffland(grid, x, y-1);
        }
        if(y<y_len-1 && grid[y+1][x]==1)
        {
            turnOffland(grid, x, y+1);
        }
        if(x>0&& grid[y][x-1]==1)
        {
            turnOffland(grid, x-1, y);
        }
        if(x<x_len-1 && grid[y][x+1]==1)
        {
            turnOffland(grid, x+1, y);
        }
    }
    int x_len, y_len;
};


int main()
{
    vector<vector<int>> grid = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    printGrid(grid);
    Solution so;
    cout<<so.numEnclaves(grid);
}


