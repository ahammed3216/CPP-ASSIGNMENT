#include<iostream>
#include<list>

using namespace std;
int main()
{
    clock_t start,end;
    start=clock();
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

   list<int>::iterator slow=list1.begin();
   list<int>::iterator fast=list1.begin();

    while(fast != list1.end() && next(fast) != list1.end())
    {
        slow++;
        fast=next(fast,2);
    }

    cout<<"the middle value is :"<<*slow;
    end=clock();
    std::cout<<"Time:"<<(end-start)<<std::endl;
    return 0;
}
