//12345
// 15 2 4 3

#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    // ListNode* fre;
    ListNode*next;
    ListNode(int val):val(val),next(nullptr){};
    ListNode():val(0),next(nullptr){};
};

void resortListNode(ListNode* &head)  //头节点的前一个节点
{
    ListNode *p = head->next;
    if(p==nullptr) return;
    vector<ListNode*> map;
    while(p!=nullptr)
    {
        map.emplace_back(p);
        p=p->next;
    }
    int i=0;    //头节点位置
    int j = map.size()-1;   //尾节点位置
    while(i<j)
    {
        map[i]->next = map[j];
        i++;
        if(i==j) break;
        map[j]->next = map[i];
        j--;
    }
    map[i]->next=nullptr;
}

int main()
{
    string input = "1,2,3,4,5,6,7";
    // cin>>input;
    ListNode *head = new ListNode();
    ListNode *p = head;
    bool tag = false;
    int temp = 0;
    for(int i =0;i<input.size();i++)
    {
        if(input[i]>='0'&&input[i]<='9')
        {
            temp = temp*10 +(input[i]-'0');
            tag =true;
        }
        else 
        {
            if(tag == true)  //判断存在逗号意外的参数
            {
                p->next = new ListNode(temp);
                p = p->next;
                tag = false;
                temp = 0;
            }
            
        }
    }
    if(tag ==true)
    {
        p->next = new ListNode(temp);
        p = p->next;
        temp = 0;
    }
    resortListNode(head);
    p = head->next;
    while(p->next!=nullptr)
    {
        cout<<p->val<<',';
        p=p->next;
    }
    cout<<p->val;
    return 0;
}

