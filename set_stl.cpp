#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main()
{
    set<int>data={10,1,9,76};

    for(set<int>::iterator i=data.begin();i!=data.end();i++)
    {

        cout<<*i<<"\t"<<endl;
    }

    data.insert(10);
    data.insert(4);
    data.insert(67);


    set<int>::iterator i=data.begin();
    data.erase(i);

    cout<<"after erase and insertion";
    
    for(set<int>::iterator i=data.begin();i!=data.end();i++)
    {

        cout<<*i<<"\t"<<endl;
    }


    



}