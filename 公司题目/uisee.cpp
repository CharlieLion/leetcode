#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if(pHead==nullptr) return pHead;
        ListNode *p= new ListNode(0);  //指向head前一个节点
        ListNode *q= new ListNode(0);
        ListNode *r = p;
        ListNode *s = q;

        while(pHead!=nullptr)
        {
            if(pHead->val<x)
            {
                r->next = pHead;
                r = r->next;
            }
            else{
                s->next = pHead;
                s = s->next;
            }
            pHead = pHead->next;
        }
        r->next = q->next;
        s->next = nullptr;
        return p->next;
        
    }
};

int main()
{
    vector<int>arr ={3,3,4,5,6,1};
    ListNode *pHead = new ListNode(arr[0]);
    ListNode *p = pHead;
    for(int i=1,n = arr.size();i<n;i++)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Partition pa;
    pa.partition(pHead,2);
    return 0;
}