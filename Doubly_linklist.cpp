#include<iostream>
using namespace std;
class doubly_linklist
{
    public:
    struct node
    {
        int data;
        node* next;
        node* pre;
    };
    node*head;
    int size;
    public:
    doubly_linklist()
    {
       
        head=NULL;
        size=0;
    }
    node* create(int data)
    {   size++;
        node* newnode=new node;
        newnode->data=data;
        newnode->next=NULL;
        newnode->pre=NULL;
        return newnode;
    }
    void push_front(int data)
    {
        node* newnode = create(data);
        if(head==NULL) head=newnode;
        head->pre=newnode;
        newnode->next=head;
        head=newnode;
        
    }
    void push_back(int data)
    {   
        node* newnode = create(data);
        node* temp=head;
        if(head==NULL) head=newnode;
        for(int i=0;i<size;i++)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
    }
    void display()
    {
        node* temp=head;
        for(int i=0;i<size;i++)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    void replace(int pos,int data)
    {
        node* temp = head;
        if(head==NULL) 
        {cout<<"empty"<<endl; return;}

        if(pos == 0) head->data=data;
        else
        {
            for(int i=0;i<pos-1;i++) temp=temp->next;
            (temp->next)->data=data;
        }
        
    }
    void reverse()
    {
        node* temp=head;
        if(temp == NULL)  return;
        for(int i=0;i<size;i++) temp=temp->next;
        for(int i=0;i<size;i++)
        {
            cout<<temp->data<<endl;
            temp=temp->pre;
        }
        cout<<endl;
    }


};
int main()
{
    doubly_linklist o;
    o.push_front(0);
    o.display();
    o.push_front(99);
    o.display();
    o.reverse();

    
    return 0;
}