#include<iostream>
using namespace std;
int main()
{
    const int*ptr;
    int val=10;
    ptr=&val;
    //*ptr=10; invalid
 
    int *mutable_ptr=const_cast<int*>(ptr);

    *mutable_ptr=20;

    cout<<*mutable_ptr;
}