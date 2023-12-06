#include<iostream>
#include<cstdint>
using namespace std;
int main()
{
	int8_t n=0,*dynamic_array,total=0,i=0;
	
	cout<<"How many data is needed to store the elements :";
	cin>>n;
	cout<<"\nThe value of the n is "<<n;
	dynamic_array=new int8_t[n];

	if(dynamic_array==NULL)
	{
	
		cout<<"\nThe pointer initialization is failed\n";
	
	}
	else
	{
	
		for(i=0;i<n;i++)
		{
		cout<<"The value of the i is "<<i;
		cout<<"ENter the data ";
		cin>>*(dynamic_array+i);

		
		
		}

		cout<<"\nEnter the data to find the total";
		cin>>total;
		
	
	
	}






}
