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

void level_order(node *root)
{
   if(root==NULL) return;
   queue<node *> Q;
   Q.push(root);
   while(!Q.empty())
   {
       node *current=Q.front();
       cout<<current->data<<"  ";
       if(current->left != NULL) Q.push(current->left);
       if(current->right != NULL) Q.push(current->right);
       Q.pop();
   }
}

void preorder(node *root)
{
 if(root==NULL) return;
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right);

}

void inorder(node *root)
{ if (root==NULL) return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

void postorder(node *root)
{ if (root==NULL) return;
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";  
}


int main()
 {  
     node *root=NULL;
     root=insert(root,7);
     root=insert(root,4);
     root=insert(root,9);
     root=insert(root,1);
     root=insert(root,6);
    cout<<"LEVEL ORDER: ";
    level_order(root);
    cout<<endl;
    cout<<"PREORDER: ";
    preorder(root);
    cout<<endl;
    cout<<"INORDER: ";
    inorder(root);
    cout<<endl;
    cout<<"POSTORDER: ";
    postorder(root);
    cout<<endl;
    

     return 0;

 }