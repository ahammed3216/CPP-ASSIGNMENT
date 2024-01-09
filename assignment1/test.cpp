#include<iostream>
using namespace std;
class car
{
    public:
        int model;
    
    public:
        car(int id):model(id){}

};

int main()
{
    //deep copy
    car c1(2000);
    car c2=c1;
    c2.model=3000;

    //shallow copy
    car *c3=&c1;

    car *ptr=new car(500);
}