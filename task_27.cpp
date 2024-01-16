#include<iostream>
#include<memory>
using namespace std;
class Minstack
{
    private:
        unique_ptr<int[]>dynamic_array;
        
        int top;
        int size;
        
    
    public:

        Minstack(int val): size(val), dynamic_array(make_unique<int[]>(size))
        {
            
        }

        void push(int val)
        {
            
             if(top>size)
            {
                cout<<"Stack is overflow!!!\n";
                return;
            }
            cout<<"push the value sucessfully\n";
            
            dynamic_array[top]=val;
            top++;
            
            

        }

        void pop()
        {
            if(top==-1)
            {
                cout<<"The stack is underflow!!!\n";
                return;
            }
            else if(top>size)
            {
                top--;
            
            }
            
            
            cout<<"poped out sucessfully"<<endl;
            cout<<"The value from the top of the stack is"<<dynamic_array[top]<<"\t"<<endl;
            top--;
            
            
        }

        int top_output()
        {
            if(top<0)
            {
                cout<<"stack is empty!!\n";
                return -1;
            }
            else if(top>size)
            {
                
                cout<<"The value from the top of the stack is"<<dynamic_array[top-1]<<"\t"<<endl;
                return dynamic_array[top];

            }
            else
            {
                cout<<"The value from the top of the stack is"<<dynamic_array[top]<<"\t"<<endl;
                return dynamic_array[top];
            }
        }

        int getMin()
        {
            if(top<0)
            {
                cout<<"The stack is empty\n";
                return -1;
            }
            else
            {   
                int min=dynamic_array[0];
                for(auto i=1;i<top;i++)
                {
                    if(dynamic_array[i]<min)
                    {
                        min=dynamic_array[i];
                    }
                }
                return min;
            }
        }
};

int main()
{
    unique_ptr<Minstack>ptr=make_unique<Minstack>(5);
  
    ptr->push(1);
    ptr->push(2);
    ptr->push(3);
    ptr->push(4);
    ptr->push(5);
    ptr->push(6);
    ptr->push(6);
    ptr->top_output();
    ptr->getMin();
    ptr->pop();
    ptr->pop();
    ptr->pop();
    ptr->pop();
    ptr->pop();
    ptr->pop();
    ptr->pop();
    ptr->pop();


    ptr->top_output();
    ptr->getMin();

}