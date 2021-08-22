#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left_child;
    TreeNode *right_child;
    TreeNode(int val):val(val),left_child(nullptr),right_child(nullptr){};
    TreeNode():val(0),left_child(nullptr),right_child(nullptr){};
};

bool boolSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    bool result=false;
    if(pRoot2==nullptr) return true;
    if(pRoot1->val ==pRoot2->val)
    {
        result = boolSubTree(pRoot1->left_child,pRoot2->left_child)&&boolSubTree(pRoot1->right_child,pRoot2->right_child);
    }
    return result;
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    bool result =false;
    if(pRoot1!=nullptr&&pRoot2!=nullptr)
    {
        if(pRoot1->val==pRoot2->val)
        {
            result = boolSubTree(pRoot1,pRoot2);
        }
        if(!result)
        {
            result = HasSubtree(pRoot1->left_child,pRoot2);
        }
        if(!result)
        {
            result = HasSubtree(pRoot1->right_child,pRoot2);
        }
    }
    return result;
    
}

int main()
{
    TreeNode *p1 =new TreeNode(8);
    TreeNode *pp1 =p1;
    pp1->left_child = new TreeNode(8);
    pp1->right_child = new TreeNode(7);
    pp1 = pp1->left_child;
    pp1->left_child = new TreeNode(9);
    pp1->right_child = new TreeNode(2);
    pp1 = pp1->right_child;
    pp1->left_child = new TreeNode(4);
    pp1->right_child = new TreeNode(7);

    TreeNode *p2 = new TreeNode(8);
    p2->left_child =new TreeNode(9);
    p2->right_child = new TreeNode(7);
    cout<<HasSubtree(p1,p2)<<endl;

}