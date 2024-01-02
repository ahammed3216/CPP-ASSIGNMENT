/*"Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle nod"*/

#include<iostream>
#include<list>

using namespace std;
template<class T>
int MiddleElement(list<T>& list1);
int main()
{
    int result=0;
    list<int>list1;
    // list1.push_back(6);
    // list1.push_back(7);
    // list1.push_back(8);
    // list1.push_back(9);
    // list1.push_back(10);
    // list1.push_back(20);
    // list1.push_back(30);
   list1.emplace_back(6);
   list1.emplace_front(7);
   list1.emplace_back(3);
   list1.emplace_back(1);
   list1.emplace_front(10);
   list1.emplace_back(11);

   result=MiddleElement(list1);

   cout<<"the middle value is :"<<result;
  
    return 0;
}


template<class T>
int MiddleElement(list<T>& list1)
 {
    // Using '&' operator to get the address of the list

     list<int>::iterator slow=list1.begin();
   list<int>::iterator fast=list1.begin();

    while(fast != list1.end() && next(fast) != list1.end())
    {
        slow++;
        fast=next(fast,2);
    }

    
    return *slow;
  
}
