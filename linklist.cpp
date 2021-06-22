#include<iostream>
using namespace std;
class linklist
{
    public: 
        struct node
        {
            int data;
            node* link;
        };
        node* head;
       
        int size;
        bool deleted;
        node* create(int data)
        {   size++;
            node* newnode=new node;
            newnode->data=data;
            newnode->link=NULL;
            return newnode;
        }
    public:
        linklist()
        {
            head=NULL;
            size=0;
            deleted=false;
        }
        
        void push_front(int data)
        { 
            node* newnode=create(data);
            if(head != NULL)
            {
                newnode->link=head;
            }
            head=newnode;
        }
        void push_back(int data)
        {
            node* newnode=create(data);
            if(head == NULL)
            {
                head=newnode;
            }
            else
            {
                node* ptr =head;
                while(ptr->link !=NULL)
                {
                    ptr=ptr->link;
                }
                ptr->link=newnode;
            }
        }
        void insert_at(int pos,int data)
        {
            if(pos == 0)
            {
                node* newnode=create(data);
                head=newnode;
            }
            else
            {   node* ptr=head;
                node* newnode=create(data);
                for(int i=0;i<pos-1;i++)
                {
                    ptr=ptr->link;
                }
                newnode->link=ptr->link;
                ptr->link=newnode;          
            }
        }
        void remove_at(int pos)
        {   size--;
            if(head==NULL) cout<<"empty list"<<endl;
            if(pos==0)
            {
                node* ptr=head;
                head=ptr->link;
                delete ptr;
                return;
            }
            node* ptr =head;
            for(int i=0;i<pos-1;i++)
            {
                ptr=ptr->link;
            }
            node* temp=ptr;
            ptr->link=ptr->link->link;
            delete ptr->link;
        }
        void pop_front()
        {
            
            if(head==NULL) cout<<"empty list"<<endl;
            else
            {
                node* ptr=head;
                head=ptr->link;
                delete ptr;
               
            }
            size--;
        }
        void pop_last()
        { 
            
            if(head==NULL) cout<<"empty list"<<endl;
            node* ptr=head;
            
            for(int i=0;i<size-2;i++)  
            {
                ptr=ptr->link;
            }
            node* temp=ptr;
            temp->link=NULL;
            delete ptr->link;
            size--; 
        }  
        

        void replace(int pos,int data)
        {   
            node* ptr=head;
            if(pos==0) ptr->data=data;
            else if(pos<size-1)
            {
                for(int i=0;i<pos-1;i++) ptr=ptr->link;
                ptr->link->data=data;
            } 
            else cout<<"replace element pos <= "<<size-1; 
        }

        void get_size()
        {
            cout<<size<<endl;
        }

        void reverse_linklist()
        {
            node* current,*pre=NULL,*next;
            current=head;
            for(int i=0;i<size;i++)
            {
                next=current->link; 
                current->link=pre; //cureent of link is linked to address stored in pre
                pre=current; //pre will be assigned with the address stored in current
                current=next;//current will be assigned with the adress stored in next
            }
            head=pre; //last node linked to adresses stored in pre

        }
        void display_reverse(node *head)
        {

            if(head==NULL) return;
            display_reverse(head->link);
            cout<<head->data<<endl;
        }
        void delete_linklist()
        {
            node* temp=head,*ptr;
            while(temp->link != NULL)
            {
                ptr=temp;
                temp=temp->link;
                delete ptr;
                size--;
            }
            delete temp;
            size--;
            deleted=true;
        }
        /*~linklist()
        {
            if(!deleted)
            {
                delete_linklist();
            }
            cout<<"List deleted: Releasing memory"<<endl;
        }*/
        
        int at(int pos)
        {
            node* temp=head;
            for(int i=0;i<pos;i++) temp=temp->link;
            return temp->data;
        }

        void reverse_2() 
        {
            for(int i=size-1;i>=size/2;i--)
            {
                int temp=at((size-1) - i); //1st position
                replace((size-1)-i,this->at(i));
                replace(i,temp);
            }
        }

        void display()
        {   if(size==0) cout<<"No element found"<<endl;
            else
            {   node* ptr =head;
                for(int i=0;i<size;i++)
                {
                    cout<<ptr->data;
                    if(ptr->link!=NULL) cout<<"-->";
                    ptr=ptr->link;
                }
                cout<<endl;
            }
        }
};
int main()
{
    linklist o;
    for(int i=0;i<8;i++) o.push_front(i);
    for(int i=0;i<8;i++) o.push_back(i);
    o.display();
    for(int i=0;i<10;i++)
    {
        o.replace(i,(o.at(i)+1));
    }
    o.display();
    o.reverse_2();
    o.display();
    
    return 0;
}
