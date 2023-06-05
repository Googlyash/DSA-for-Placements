#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//Definition of Node for Binary search tree
struct BtsNode
{
  ll data;
  BtsNode* left;
  BtsNode* right;
};

// Function to create a new Node in heap
BtsNode* GetNewNode(ll data)
{
    BtsNode* node=new BtsNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

// To insert data in BST, returns address of root node
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

//Finding Min Recursively
ll FindMin(BtsNode* root)
{
    if(root==NULL)
    {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->left ==NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

//Finding Max Recursively
ll FindMax(BtsNode* root)
{
    if(root==NULL)
    {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->right ==NULL)
    {
        return root->data;
    }
    return FindMin(root->right);
}

//Finding Height Recursively
ll FindHeight(BtsNode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+max(FindHeight(root->right),FindHeight(root->left));
}


int main()
{
    BtsNode* root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);
   
    cout<<"Min Element in BST is: "<<FindMin(root)<<endl;
    cout<<"Max Element in BST is: "<<FindMax(root)<<endl;
    cout<<"Height of BST is: "<<FindHeight(root)<<"\n";
    
    return 0;
}
