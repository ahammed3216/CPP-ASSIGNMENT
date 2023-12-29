#include<iostream>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;
int main()
{
    unordered_map<char,int>count;
    string str="ahammedunny";
    string palindrome;
    bool flag;
    char oddChar='\0';

    for(char ch:str)
    {
        
        count[ch]++;
    }

    for(auto i=count.begin();i!=count.end();i++)
    {
        cout<<i->first<<"\t"<<i->second<<endl;
    }

    for(const auto &obj:count)
    {
        int value=obj.second;
        if(value%2 ==0)
        {
            string half(value/2,obj.first);
            palindrome=half+palindrome+half;
        }
        else
        {
            string half((value-1)/2,obj.first);
            palindrome=half+palindrome+half;
            flag=true;
            oddChar=obj.first;

        }
    }
    if(flag==true)
    {
        palindrome=palindrome.substr(0,palindrome.size()/2)+oddChar+palindrome.substr(palindrome.size()/2);
    }

    cout<<"\nThe palindrome string is :"<<palindrome;
    cout<<"\nSize od the The palindrome string is :"<<palindrome.size();
}