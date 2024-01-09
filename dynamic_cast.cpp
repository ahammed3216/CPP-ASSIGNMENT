#include<iostream>
#include<memory>
using namespace std;
class Parent
{
    private:
        int data;
    public:
        Parent()
        {
            cout<<"\nconstrutor if the base class is called :";
        }
        virtual void test()
        {
            cout<<"\nin the base class";
        }
        virtual ~Parent()
        {
            cout<<"\ndestructor of the base class is called";
        }
    
};
class child:public Parent
{
    private:
        int more_data;

    public:
        child()
        {
            cout<<"\nconstrutor if the child class is called :";
        }
        void test()
        {
            cout<<"\nin the chid class";
        }
         ~child()
        {
            cout<<"\ndestructor of the child class is called";
        }
};
int main()
{
    unique_ptr<Parent>ptr1=make_unique<child>(); 
    //Parent *ptr1=new child();  
    ptr1->test();
    child *ptr=dynamic_cast<child*>(ptr1.get());
    
    //delete(ptr);
    if(ptr==nullptr)
    {
        cout<<"\ndynamic cast failed";
    }
    else
    {
        ptr->test();
        ptr->Parent::test();
    }
    
}