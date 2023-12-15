#include<iostream>
#include<memory>
using namespace std;
template<class T>
class Person
{
    private:
        T age;

    public:
        Person()
        {
            cout<<"Person Constructor is called ";
        }
        virtual ~Person()
        {
            cout<<"\nperson Destructor is called ";
        }

};

template <class U>
class Child : public Person<U>
{

    public:
        Child()
        {
            cout<<"\nChild classConstructor is called ";

        }

        ~Child()
        {
            cout<<"\nChild class destructor is called ";

        }
};

int main()
{
    unique_ptr<Person<int>>ptr(new Child<int>());

    //Person <int>obj;
    //Child<int>obj1;

    
    
}