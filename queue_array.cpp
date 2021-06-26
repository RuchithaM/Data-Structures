#include <iostream>
using namespace std;
class queue
{
public:
    int queue[100], n = 100, front = - 1, rear = - 1;
public:
    void enqueue(int x) 
    {
        if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
        else
        {
            if (front == - 1)
            front = 0;
            rear++;
            queue[rear] = x;
        }
}
void dequeue() 
{
   if (front == - 1 || front > rear) 
   {
      cout<<"Queue Underflow ";
      return ;
   } 
   else 
   {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}
void Display() 
{
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else 
   {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
   }
   cout<<endl;
}
};
int main() 
{
    queue o;o.enqueue(5);
    o.enqueue(6);
    o.Display();
    o.dequeue();
    o.Display();
   
    return 0;
   
}