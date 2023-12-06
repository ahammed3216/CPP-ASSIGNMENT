#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the age :";
    cin>>num;
    try
    {
        if(num<18)
        {
            throw num;
        }
        else
        {
            cout<<endl<<"sucessfull authentication";

        }

    }
    catch(int x)
    {
        cout<<endl<<"your age must be grteater than 18 for this programme";
    }
    




}