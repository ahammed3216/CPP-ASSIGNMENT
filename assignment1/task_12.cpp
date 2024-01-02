#include<iostream>
#include<map>
#define NO_OF_VERISONS 10
#define VERSION1 "good"
#define VERSION2 "bad"
using namespace std;
map<int,string>version;
bool APIcheck(int version_no);
int main()
{
    bool flag=true,check=false;
    int version_no,check_ver=0;
    

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

    // cout<<"\nDisplaying the version values :\n";

    // map<int,string>::iterator i;

    // for(i=version.begin();i!=version.end();i++)
    // {
    //     cout<<i->first<<"\t"<<i->second<<endl;
    // }

    cout<<"ENter the version to check ";
    cin>>check_ver;
    check=APIcheck(check_ver);
    if(check==true)
    {
        cout<<VERSION1;
    }
    else
    {
        cout<<VERSION2;
    }




}

/*
 * @func-name : APIcheck
 * @function_description:recieves the veriosn no and retturn the version of the code
 * @return : return the true and flase
 */
bool APIcheck(int version_no)
{
    if(version[version_no]==VERSION1)
    {
        return true;
    }
    else
    {
        return false;
    }
}