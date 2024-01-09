#include<iostream>
using namespace std;
int main()
{
    int val=10;
    int val1=20;
    const int*ptr =&val;
    ptr=&val1;
    //*ptr=30; invalid 
    cout<<*ptr; 

    int *const ptr1=&val;
    *ptr1=30;
    //ptr1=&val1; not valid

    const int *const ptr4=&val1;
   // *ptr4=50; not possibke
   // ptr4=&val; not possible
}