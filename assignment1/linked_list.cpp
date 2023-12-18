#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main()
{
    list<int>list1;
    list1.push_back(6);
    list1.push_back(7);
    list1.push_back(8);
    list1.push_back(9);
    list1.push_back(10);
    
   

   list<int>::iterator slow=list1.begin();
   list<int>::iterator fast=list1.begin();

    while(fast != list1.end() && next(fast) != list1.end())
    {
        slow++;
        fast=next(fast,2);
    }

    cout<<"the middle value is :"<<*slow;

   
}
