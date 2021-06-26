#include<iostream>
#include<stack>
using namespace std;

bool check(string exp)
{   char ch;
    int len=exp.length();
    stack <char> stack;
    for(int i=0;i<len;i++)
    {
        if(exp[i] == '(' or exp[i] == '[' or exp[i] == '{')
        {
            stack.push(exp[i]);
            continue;
        }
        
        if(stack.empty())  return false;
            switch(exp[i])
            {
                case '}': 
                    {
                        ch=stack.top();
                        stack.pop();
                        if(ch=='(' or ch=='[') return false;
                        break;
                    }
                case ']':
                    {
                        ch=stack.top();
                        stack.pop();
                        if(ch=='(' or ch=='{') return false;
                        break;    
                    }
                case ')': 
                    {
                        ch=stack.top();
                        stack.pop();
                        if(ch=='{' or ch=='[') return false;
                        break;
                    }
            }
           
        }
    
    return(stack.empty());


}


int main()
{
    string e;
    cin>>e;
    bool r=check(e);
    cout<<r;
    return 0;
}