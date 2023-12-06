#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

float SquareArea(void);
void StringInput(void);
int main()
{


	//SquareArea();
	StringInput();
	// uint8_t value=0;
	
	// const int age=4;
	// bool check;
	// int *ptr;
	// ptr=new(nothrow)int;

	// string name="ahammedunny navas";

	// check=false;
	// cout<<"The value in the check variable is "<<check<<"\n";
	// cout<<"The size of the boolean variable is "<<sizeof(bool)<<"\n";

	// cout<<"-----------------------------------------------------------------------------------\n";
	// cout<<"The value that holds in the name variable"<<name<<"\n";
	// cout<<"The size of the string varible is "<<sizeof(name)<<"\n";
	// cout<<"------------------------------------------------------------------------------------\n";
	// cout<<"The size of the pointer is :"<<sizeof(ptr);
	// {
	// 		int age=22;
	// 		age++;
	// 		cout<<"hello\n""world\n";




	// }
return 0;





}


float SquareArea(void)
{
	float length=0,area=0;
	cout<<"Enter the length of the square :";
	cin>>length;
	area=length *length;
	cout<<endl<<"The area of the square is "<<area;
}

void StringInput(void)
{
	
	string first_name,last_name,address;
	cout<<"Enter your first name :\n";
	getline(cin,first_name);
	cout<<"Enter your last name :";
	getline(cin,last_name);
	cout<<"Enter your adress:";
	getline(cin,address);



}