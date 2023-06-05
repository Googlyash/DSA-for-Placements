//Checking if given tre is BinarySearchTree or not
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct BtsNode
{
  ll data;
  BtsNode* left;
  BtsNode* right;
};
BtsNode* GetNewNode(ll data)
{
    BtsNode* node=new BtsNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
BtsNode* Insert(BtsNode* root,ll data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
        return root;
    }
    if(data<= root->data)root->left=Insert(root->left, data);
    else if(data>= root->data)root->right=Insert(root->right,data);
    return root;
}

/*---------------------------------------------------------------------------Function COde Starts-------------------------------------------------------------------------- */
//Function called from BST_check function
bool BstUtil(BtsNode*root, int minVal, int maxVal)
{
    if(root==NULL)return 1;
    
    if(root->data >minVal && root->data< maxVal && BstUtil(root->left,minVal, root->data) && BstUtil(root->right,root->data, maxVal))
    {
        return true;
    }
    return false;
}

//Function called from main
bool BST_check(BtsNode* root)
{
    return BstUtil(root,INT_MIN, INT_MAX);   
}

/*---------------------------------------------------------------------------Function COde Ends-------------------------------------------------------------------------- */

int main()
{
    BtsNode* root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);
    root=Insert(root,19);
    cout<< ((BST_check)? "Given Tree is Binary Search Tree": "Given Tree is not Binary Search Tree");
    return 0;
}
