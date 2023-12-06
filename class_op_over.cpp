#include<iostream>
#include<string>
using namespace std;
class Person
{
    private:
        int age;
    
    public:
        Person (int x=0)
        {

            age=x;
        }

        Person operator+(Person p)
        {

            Person temp;
            temp.age= age +p.age;
            return temp;
        }


        void print_age()
        {


            cout<<"The age of the person is "<<age;
        }


        void operator++()
        {

            age++;
        }

        void operator++(int)
        {

            ++age;
        }

};
int main()
{

    Person p1=(70);
    Person p2=(30);
    Person total;

    total= p1 + p2;

    ++total;
    total.print_age();


    return 0;

}