#include<iostream>
#include<queue>

using namespace std;
int main()
{

    priority_queue<int>queue1; //max heap
    priority_queue<int,vector<int>,greater<int>>queue2;

    queue1.push(1040);
    queue1.push(1030);
    queue1.push(1200);

    cout<<"the top element is";

    cout<<queue1.top();

    queue1.pop();

    cout<<endl<<"the top element is";
    cout<<queue1.top();

    cout<<endl<<"Min heap implemetation"<<endl;

    queue2.push(140);
    queue2.push(30);
    queue2.push(200);


     cout<<"the top element is";

    cout<<queue2.top();

    queue2.pop();

    cout<<endl<<"the top element is";
    cout<<queue2.top();







}