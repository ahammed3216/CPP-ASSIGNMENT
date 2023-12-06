#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout<<"top element is :"<<queue.front()<<endl;
    cout<<"back element is :"<<queue.back()<<endl;

    queue.pop();
    cout<<"\nAfter the pop operation";

    cout<<"top element is :"<<queue.front()<<endl;
    cout<<"back element is :"<<queue.back()<<endl;





}