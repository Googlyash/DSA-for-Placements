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
void bfs(BtsNode* root)
{
    if(root==NULL)
    {
        return;
    }
    std::queue<BtsNode*> Q ;
    Q.push(root);
    while(!Q.empty())
    {
        BtsNode* curr= Q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL)Q.push(curr->left);
        if(curr->right!=NULL)Q.push(curr->right);
        Q.pop();
    }
    return;
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
    bfs(root);
    
    return 0;
}
