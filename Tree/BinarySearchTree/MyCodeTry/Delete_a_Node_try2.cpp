#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node
{
    ll data;
    node* left;
    node* right;
};
node* FindMin(node* root)
{
    if(root==NULL || root->left==NULL)
    {
        // cout<<"Error, tree is empty";
        return root;
    }
    while(root->left!=NULL)root=root->left;
    return root;
}
node* Insert(node* root, ll data)
{
    if(root==NULL)
    {
        root=new node();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data< root->data){root->left=Insert(root->left, data);}
    else if(data> root->data) root->right=Insert(root->right,data);
    return root;
    
}
node* DeleteNode(node* root, ll data)
{
    if(root==NULL)return root;
    if(data <root->data)root->left= DeleteNode(root->left,data);
    else if(data > root->data)root->right= DeleteNode(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL; 
            return root;
        }
        else
        {
            if(root->left==NULL)
            {
                node* temp= root;
                root=root->right;
                delete temp;
            }
            else if( root->right==NULL)
            {
                node* temp=root;
                root=root->left;
                delete temp;
            }
            else
            {
                node* temp= FindMin(root->right);
                root->data=temp->data;
                root->right=DeleteNode(root->right,temp->data);
            }
        }
    }
    return root;
}
void bfs(node* root)
{
    if(root==NULL)return ;
    queue<node*>q ;
    q.push(root);
    // cout<<0;
    while(!q.empty())
    {
        node* temp=q.front();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        q.pop();
    }
    return;
}
void Inorder(node*root)
{
    if(root==NULL)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main()
{
    node* root=NULL;
    root=Insert(root, 12);
    root=Insert(root, 15);
    root=Insert(root, 5);
    root=Insert(root,3);
    root=Insert(root, 7);
    root=Insert(root,1);
    root=Insert(root,9);
    root=Insert(root,13);
    root=Insert(root,17);
    root=Insert(root, 20);
    root=Insert(root, 25);
    Inorder(root);
    cout<<"\n";
    DeleteNode(root, 17);
    Inorder(root);
    cout<<"\n";
    cout<<"Hello World";

    return 0;
}
