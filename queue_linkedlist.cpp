#include<iostream>
using namespace std;

class queue
{
    public: struct node
    {
        int data;
        node* next;
    };
    struct node *front,*rear;
    int size;
    queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    node* create(int data)
    {   size++;
        node *temp=new node;
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
    bool isempty()
    {
        if(front==NULL && rear==NULL) return true;
        else return false; 
    }
    void enqueue(int data)
    {
        node *newnode=create(data);
        if(isempty())
        {
            front=newnode;
            rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=rear->next;
        }
    }
    void f()
    {
        cout<<front->data<<endl;
    }
    void dequeue()
    { size--;
        if(front==rear) {front=rear=NULL;}
        else if(!isempty())
        {
            node *temp=front;
            front=front->next;
            delete temp;
        }
    }

};
int main()
{
    queue o;
    o.enqueue(5);
    o.enqueue(6);
    o.enqueue(9);
    o.f();
    o.dequeue();
    o.f();
    o.enqueue(9);
    cout<<o.size;
}
