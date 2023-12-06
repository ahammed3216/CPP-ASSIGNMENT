#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;
void exchange(int8_t *num1,int8_t *num2);
int main()
{

	int8_t num1=10,num2=20;
	cout<<"The value before the exchage is"<<num1<<"\t"<<num2<<"\t\n";
	exchange(&num1,&num2);
	cout<<"The value after the exchange is "<<num1<<"\t"<<num2<<"\t\n";
	





}

void exchange(int *num1,int *num2)
{


	
	int8_t temp=0;
	temp=*num1;
	*num1=*num2;
	*num2=temp;

}
