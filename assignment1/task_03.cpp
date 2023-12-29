#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    int num1=0,num2=0,sum=0;
    string str1,str2;
    cout<<"Enter the first number :";
    cin>>num1;
    cout<<"\nEnter the second number :";
    cin>>num2;

    bitset<8>binaryvalue1(num1);
    bitset<8>binaryvalue2(num2);

    cout<<"\nBinary value of num1 :"<<binaryvalue1;
    cout<<"\nBinary value of num2 :"<<binaryvalue2;

    sum=(binaryvalue1.to_ulong()+binaryvalue2.to_ulong());
    bitset<8>sum_value(sum);

    cout<<"\nsum value of num1 and num2 in decimal:"<<(binaryvalue1.to_ulong()+binaryvalue2.to_ulong());
    cout<<"\nsum value of num1 and num2 in binary:"<<sum_value;
}