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
{   
    if(root==NULL) return -1;
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root->data;
}

int find_min(node *root)
{
    if(root==NULL) return -1;
    else if(root->left==NULL) { return root->data;}
    return find_min(root->left);
}

int find_max(node *root)            // max will always be right size
{
    if(root==NULL) return -1;
    else if(root->right==NULL) return root->data;
    return find_max(root->right);
}


int find_height(node *root)
{
    if(root==NULL) return -1;
    else
    {   
        int left_height=find_height(root->left);
        int right_height=find_height(root->right);
        return max(left_height,right_height)+1;

     }
}

node* find_min_address(node *root)
{
    if(root==NULL) {return NULL;}
    else if(root->left==NULL){return root;}
    return find_min_address(root->left);
}

node *delete_tree(node *root,int data)
{   if(root==NULL) return root;
    else if(data < root->data)  {root->left=delete_tree(root->left,data);}
    else if (data > root->data) {root->right=delete_tree(root->right,data);}
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }

        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            delete temp;
        }
        else if (root->right==NULL)
        {
            node *temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            node *temp=find_min_address(root->right);
            root->data=temp->data;
            root->right=delete_tree(root->right,temp->data);
        }
    }
    return root;
}



 int main()
 {   
     node *root=NULL;
     root=insert(root,7);
     root=insert(root,4);
     root=insert(root,9);
     root=insert(root,1);
     root=insert(root,6);

    cout<<search(root,9)<<endl;
    cout<<find_max_iterative(root)<<endl<<endl;
    cout<<find_min(root)<<endl<<endl;
    cout<<find_height(root->left)<<endl<<endl;
    delete_tree(root,1);
    cout<<find_min(root);
    
     return 0;

 }