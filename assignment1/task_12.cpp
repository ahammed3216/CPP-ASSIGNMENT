#include<iostream>
#include<map>
#define NO_OF_VERISONS 10
#define VERSION1 "good"
#define VERSION2 "bad"
using namespace std;
int main()
{
    bool flag=true;
    int version_no;
    map<int,string>version;

 again:
    cout<<"Enter the bad version of the software :";
    cin>>version_no;

    if(version_no <=0 || version_no >10)
    {
        cout<<"the version is out of range !!!Please contact the admin team\n";
        goto again;
    }

    for(auto i=1;i<=NO_OF_VERISONS;i++)
    {
        if(i==version_no || flag ==false)
        {
            version[i]=VERSION2;
            flag=false;
        }
        else
        {
            version[i]=VERSION1;
        }
    }

    cout<<"\nDisplaying the version values :\n";

    map<int,string>::iterator i;

    for(i=version.begin();i!=version.end();i++)
    {
        cout<<i->first<<"\t"<<i->second<<endl;
    }



}