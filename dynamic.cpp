#include<iostream>
using namespace std;
int main()
{


	int *ptr;
	ptr=new (nothrow)int;

	if(!ptr)
		cout<<"error occured";
	else
	{
		cout<<"pointer is issued with dynamic memory";
		cout<<"\nThe adress of the pointer is :"<<ptr;

	}




}
