#include<iostream>
using namespace std;
#define STACK_VALUE 50
int data[STACK_VALUE];
int count;
class stack
{

    public:
        int pos;
        void push( );
        void pop();
        void display();
        stack(int pos=-1)
        {
            this->pos=pos;
        }
        

};
void stack::push()
{
    int temp;
    if(pos==count)
    {
        cout<<"The stack is overflow"<<endl;

    }
    else
    {
        cout<<endl<<"\nEnter the data :";
        cin>>temp;
        pos++;
        data[pos]=temp;


    }

}
void stack::pop()
{
    if(pos==-1)
    {
        cout<<endl<<"the stack is underflow";
        
    }
    else
    {
        cout<<endl<<"Poping the data inside the stack"<<endl;
        cout<<data[pos];
        pos--;

    }


}

void stack::display()
{

    int i=0;
    cout<<endl<<"Displaying the contents of the data array !!!"<<endl;
    for(i=0;i<count;i++)
    {
        cout<<data[i]<<endl;
    }


}

int main()
{
    int i=0,temp=0;
    stack st1;
    char option=0;
    cout<<"ENter the number of data to be stored :";
    cin>>count;
    while(option != 'q')
    {
        cout<<endl<<"Enter 1 to push"<<endl<<"Enter 2 to pop"<<endl<<"enter 3 to display the array";
        cin>>option;
        if(option =='1')
        {
            st1.push();
        }
        else if(option =='2')
        {
            st1.pop();
        }
        else if(option=='3')
        {
            st1.display();
        }
        else if(option =='q')
        {
            break;
        }
        else
        {
            cout<<endl<<"Invalid option";
        }
    }
   

}