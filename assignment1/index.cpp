#include<iostream>
#include<set>
using namespace std;
int main()
{
    int count=0,value=0,target=0;
    multiset<int>numbers;
    cout<<"How many numbes to added :";
    cin>>count;

    for(auto i=0;i<count;i++)
    {
        cout<<"Enter the number :";
        cin>>value;
        numbers.insert(value);
    }

    cout<<"\nEnter the target :";
    cin>>target;

    auto it=numbers.find(target);
    if(it != numbers.end())
    {
        cout<<"\nthe number is found ";
    }
    else
    {
        cout<<"\nThe number is not found";
    }

}