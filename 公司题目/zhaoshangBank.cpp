#include<string>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//招行填空题，考 结构体内部重构比较函数
struct Node
{
   int val;
   Node(int val):val(val){};
   bool operator < (const Node &a)const   //_________1__________
   {
       if(val<a.val) 
       {
           return true;
       }
       return false;
   }
   bool operator > (const Node &a)const   //_________2__________
   {
       if(val>a.val) 
       {
           return true;
       }
       return false;
   }

};


int main()
{
    priority_queue<Node,vector<Node>, greater<Node>>ans;  //_________3__________
    for(int i=0;i<10;i++)
    {
        ans.push(i);                           //_________4__________
    }
    for(int i=0;i<10;i++)
    {
        Node item = ans.top();              //_________5__________
        cout<<item.val<<endl;
        ans.pop();
    }
    // getMatrix();
}