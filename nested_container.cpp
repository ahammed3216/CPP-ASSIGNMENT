#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<map>
using namespace std;
int main()
{
    vector<int> vector1;
    vector<vector <int>>vector2={{10,20,30},{40,50,60}};
    vector2.push_back({100,200,300});
    vector2[2].pop_back();

    list<list<int>>list1;
    list1.push_back({100,200,300});
    list1.push_back({1000,2000,3000});
    list1.push_back({1001,2001,3001});

   map<int,map<int,string>>m1;
   m1[0].insert(make_pair(1,"ahammed"));
   m1[1].insert(make_pair(2,"janu"));

    cout<<"\nprinting the nested vector values\n";
    for(vector<vector<int>>::iterator it =vector2.begin();it!=vector2.end();it++)
    {

            for(auto it1=it->begin();it1!=it->end();it1++)
            {
                    cout<<*it1<<"\t";

            }

            cout<<endl;
    }

    cout<<"\nprinting the nested list values\n";
       for(list<list<int>>::iterator it =list1.begin();it!=list1.end();it++)
    {

            for(auto it1=it->begin();it1!=it->end();it1++)
            {
                    cout<<*it1<<"\t";

            }

            cout<<endl;
    }


     cout<<"\nprinting the nested map values\n";
    for(map<int,map<int,string>>::iterator i= m1.begin();i!=m1.end();i++)
    {

        cout<<"outer"<<i->first<<"\t";
        for(auto it1=i->second.begin();it1!=i->second.end();it1++)
        {

               cout<<"inner"<<it1->first<<"\t"<<it1->second<<endl;

        }


    }


}