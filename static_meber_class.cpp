#include<iostream>
using namespace std;
class Box
{
    public:
         inline static int count=0;
         int check=10;
    public:
        Box()
        {
            count ++;
        }


};

//int Box::count = 0;

int main()
{
    static int value;
    cout<<value;
    Box obj1;
    cout<<obj1.check;
    
}