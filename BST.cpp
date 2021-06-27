#include<iostream>
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
    {
        root=create(data);

    }
    else if(root->data >= data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(node *root,int ele)
{
    if(root==NULL) return false;
    if(root->data==ele) return true;
    else if(root->data <= ele) return search(root->left,ele);
    else return search(root->right,ele);
    
}
int find_min_iterative(node *root)
{   if(root==NULL) return -1;
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root->data;

}

int find_max_iterative(node *root)
{   if(root==NULL) return -1;
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root->data;

}
int find_min(node *root)
{
    if(root==NULL) return -1;
    else if(root->left==NULL) return root->data;
    return find_min(root->left);
}

int find_max(node *root)
{
    if(root==NULL) return -1;
    else if(root->right==NULL) return root->data;
    return find_max(root->right);
}





 int main()
 {   node *root=NULL;
     root=insert(root,9);
     root=insert(root,10);
     root=insert(root,16);
     //cout<<search(root,9)<<endl;
     cout<<find_max_iterative(root)<<endl;
     cout<<find_min(root)<<endl;
     return 0;
 }