// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include <bits/stdc++.h>
using namespace std;

//For easeness
#define ll long long int

//Defining a Node for Binary Search Tree
struct BtsNode {
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
    if(root==NULL)     // empty tree
    {
        root=GetNewNode(data);
        return root;
    }
    // if data to be inserted is lesser, insert in left subtree.
    if(data<= root->data)root->left=Insert(root->left, data);
    // else, insert in right subtree. 
    else if(data>= root->data)root->right=Insert(root->right,data);
    return root;
}

//Search if data is present or not
//To search an element in BST, returns true if element is found
bool Search(BtsNode* root, ll data)
{
    if(root==NULL)
    {
        return 0;
    }
    if(data == root->data)return 1;
    else if(data <= root->data)
    {
      return Search(root->left,data);
    }
    else
    {
      return Search(root->right,data);
    }
}
int main()
{
    BtsNode* root=NULL;   // Creating an empty tree
    /*Code to test the logic*/
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);
    ll num;
    // Ask user to enter a number.  
    cout<<"Enter the number: ";
    cin>>num;
	//If number is found, print "FOUND"
    if(Search(root,num) == true)cout<<"Found\n";
    else cout<<"Not Found\n";
    
    return 0;
}
