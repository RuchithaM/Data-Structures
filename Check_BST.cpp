#include<iostream>
#include<queue>
using namespace std;

struct node
{
int data;
node *left;
node *right;
};

int size=0;
node* create(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert(node *root,int data)
{ size++;
    //node *newnode=create(data);
    if(root==NULL)
        root=create(data);
    else if(root->data >= data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

//1st methedology

bool issubtreelesser(node *root,int value)
{
    if(root==NULL) return true;
    if((root->data <= value) && (issubtreelesser(root->left,value) && issubtreelesser(root->right,value))) return true;
    else return false;
}
bool issubtreegreater(node *root,int value)
{
    if(root==NULL) return true;
    if((root->data > value) && (issubtreegreater(root->left,value) && issubtreegreater(root->right,value))) return true;
    else return false;
}
bool isbinarytree(node *root)
{
    if(root==NULL) return true;
    if(issubtreelesser(root->left,root->data) && issubtreegreater(root->right,root->data) && isbinarytree(root->left) && isbinarytree(root->right)) return true;
    else return false;
}

//2nd methedology

bool IsBSTUtil(node *root,int minvalue,int maxvalue)
{
    if(root==NULL) return true;
    if(root->data < minvalue && root->data > maxvalue && IsBSTUtil(root->left,minvalue,root->data) && IsBSTUtil(root->right,root->data,maxvalue))
    return true;
    else 
    return false;
}

bool IsBST(node *root)
{
    return IsBSTUtil(root,INT16_MAX,INT16_MIN);
}

int main()
 {   
     node *root=NULL;
     root=insert(root,7);
     root=insert(root,4);
     root=insert(root,9);
     root=insert(root,1);
     root=insert(root,6);
     
     cout<<isbinarytree(root)<<endl;
     cout<<IsBST(root);
    return 0;
 }