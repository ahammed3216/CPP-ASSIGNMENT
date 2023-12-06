#include<iostream>
using namespace std;
int main()
{
    int hai[5]={1,2,3,4,5};
    //int *ptr=new int[5];
    int *ptr1=new int[6];
    ptr1=hai;
    //ptr=array;
    //cout<<"The adress of the pointer 1 is "<<ptr<<endl;
    cout<<"The adress of the pointer 2 is "<<ptr1<<endl;
    //delete(ptr);
    delete(ptr1);


}