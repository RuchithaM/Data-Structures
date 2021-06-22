#include<iostream>
using namespace std;
class stack
{
    public: 
        struct node
        {
            int data;
            node* next;
        };
        node* top;
        bool empty;
        int size;
        node* create(int data)
        {   size++;
            node* newnode=new node;
            newnode->data=data;
            newnode->next=NULL;
            return newnode;
        }
    public:
        stack()
        {
            top=NULL;
            size=0;
            empty=false;
        }
    void push(int data)
    {
        node* temp=top;
        node* newnode=create(data);
        if(top==NULL) top=newnode;
        newnode->next=top;
        top=newnode;
    }
    int pop()
    {   if(top==NULL) return 0;
        else
        {
            node* temp=top;
            cout<<top->data<<endl;
            top=top->next;
            int x= temp->data;
            delete temp;
            size--;
            return x;
        }

    }
    void display()
    {
        node* temp=top;
        for(int i=0;i<size;i++)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
    bool isempty()
    {   return empty;
        
    }
    /*void reverse(node *top)
    {
        if(top==NULL) 
        {return;}
        reverse(top->next);
        cout<<top->data;
    }*/

};

int main()
{
    stack o;
    o.push(5);
    o.push(11);
    o.push(9);
    o.push(99);
    o.display();
    cout<<endl;
    //o.reverse(o.top);
    o.display();
    o.pop();
    return 0;

}