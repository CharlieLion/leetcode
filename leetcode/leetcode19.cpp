#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){};
    ListNode():val(0),next(nullptr){};
};


class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            if(head==nullptr) return nullptr;
            ListNode *front =new ListNode();
            front->next = head;
            while(n>0)
            {
                if(front==nullptr)  return nullptr;
                front = front->next;
                n--;
            }
            ListNode *back = new ListNode();
            back->next= head;
            while(front->next)
            {
                front=front->next;
                back = back->next;
            }
            ListNode *temp = back->next;
            if(temp==head) return head->next;
            back->next = temp->next;
            delete(temp);
            return head;
        }
};

int main()
{
    Solution so;
    ListNode *h,*p;
    h = new ListNode(1);
    p=h;
    for(int i=0;i<5;i++)
    {
        p->next = new ListNode(i+2);
        p = p->next;
    }
    p->next ==nullptr;
    p = h;
    while(p!=nullptr)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
    h = so.removeNthFromEnd(h,2);
    p = h;
    while(p!=nullptr)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}