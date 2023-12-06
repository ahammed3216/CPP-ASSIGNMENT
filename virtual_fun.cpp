#include<iostream>
using namespace std;
class Person
{


    private:
        int age;
    public:
        Person(int x=45)
        {
            age=x;

        }

        void show()
        {
            cout<<"inside the base class";
            cout<<this->age;
        }
};

class student:public Person
{

public:
     void show()
        {
             cout<<"inside the derrived class class";
            
        }


};
int main()
{

    Person obj1,*ptr1;
    student obj2,*ptr2;

    //wrong usage ptr2=new Person();
    //wrong usage ptr2->show();

    //ptr1=new student(); correct usage
    ptr1=new Person();
    ptr2=new student();


    ptr1->show();



}