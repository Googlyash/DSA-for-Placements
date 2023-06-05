
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
//Function to find minimum in a tree. 
BtsNode* FindMin(BtsNode* root)
{
    if(root==NULL)
    {
        cout<<"Error: Tree is empty\n";
        return NULL;
    }
    else if(root->left ==NULL)
    {
        return root;
    }
    return FindMin(root->left);
}
// Function to search a delete a value from tree.
BtsNode* Delete(BtsNode* root, ll data)
{
    if(root==NULL)return root;
    else if(data< root->data)
    {
        root->left= Delete(root->left,data);
    }
    else if(data> root->data)
    {
        root->right= Delete(root->right, data);
    }
    else
    {
        if(root->left ==NULL && root->right== NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            BtsNode* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            BtsNode*temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            BtsNode* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
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
 
//Function to visit nodes in Inorder
void Inorder(BtsNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";  //Print data
	Inorder(root->right);      // Visit right subtree
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
    Inorder(root);
    cout<<endl;
    root=Delete(root,20);
    Inorder(root);
    return 0;
}
