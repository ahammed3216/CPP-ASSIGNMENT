#include<iostream>
using namespace std;
int main()
{
    float x=3.14f;
    int y=5;
    void *ptr;
    int *ptr3;//the pointer is not initialized then it is called wild pointer
    int *ptr1=NULL;//less type security
    int *ptr2=nullptr;//it is generally used
    ptr=&y;
    cout<<*(reinterpret_cast<int*>(ptr));//deferencing only possible through the casting of that void pointer

    cout<<endl<<ptr1<<"\t"<<ptr2;

    //*ptr1 an d*ptr2 will throw segmentation fault

    //ptr++; arithmetic is not possible in the void pointer
}