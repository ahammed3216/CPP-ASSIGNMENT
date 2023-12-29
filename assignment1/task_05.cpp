#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>set1,set2;
    string str1,str2;
    cout<<"Enter the first string :";
    getline(cin,str1);
    cout<<"\nEnter the second string :";
    getline(cin,str2);

    for(char ch:str1)
    {
        set1.insert(ch);
    }

      for(char ch:str2)
    {
        set2.insert(ch);
    }

    if(set1 ==set2)
    {
        cout<<"\nThe string "<<str1<<" is the anagram of "<<str2;
    }
    else
    {
        cout<<"The string "<<str1<<" is not  the anagram of "<<str2;
    }
}