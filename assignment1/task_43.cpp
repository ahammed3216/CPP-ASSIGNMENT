#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string check_str="abba";
    int n=check_str.size(),left=0,right=0,max_length=0;
    vector<char>palindrome;

    bool count_check=true;

    if(n%2==0)
    {
        count_check=true;
    }
    else
    {
        count_check=false;
    }
    
    for (auto i=0;i<n;i++)
    {
        if(!count_check)
        {
            left=right=i;
        }
        else
        {
            left=i;
            right=i+1;
        }
       
        
        while(left>=0 && right<n && check_str[right]==check_str[left])
        {
            if(left==right)
            {
                palindrome.push_back(check_str[left]);
            }
            else
            {
                if(count_check==true)
                {
                    for(auto j=left;j<=right;j++)
                    {
                        palindrome.push_back(check_str[j]);
                    }
                }
                else
                {
                    for(auto j=left;j<right;j++)
                    {
                        palindrome.push_back(check_str[j]);
                    }
                }

            }

            left--;
            right++;
            


        }
        if(count_check==true)
        {
            max_length=right-left-1;
        }
        else
            max_length=right-left-1;
        cout<<"max_length is :"<<max_length<<endl;

        for(const auto &obj : palindrome)
        {
            cout<<obj;
        }

        palindrome.clear();

        cout<<endl;
    }
    
   

    

    

    

}