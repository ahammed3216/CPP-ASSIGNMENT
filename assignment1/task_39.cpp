#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>
using namespace std;
class MyAtoi
{
private:
    string data;
    int value;
    stack<int> result;

public:
    MyAtoi(string arr) : data(arr) {}

    int conversion()
    {
        int base = 1;
        int sign=1;
        bool sign_check = false;
        bool char_check=false;
        bool main_flag=true;
        
    
        for(auto obj:data)
        {
            if(main_flag==true)
            {
                if (obj >= 48 && obj <= 57 )
                {
                    result.push(obj-48);
                    sign_check=true;
                    char_check=true;
                }
                else if(obj==43 && sign_check==false)
                {
                    sign=1;
                    
                }
                else if(obj==45 && sign_check==false)
                {
                    sign=-1;
                }
                else if(char_check==true)
                {
                    main_flag=false;
                    cout<<"here";
                }
            }
        
        }
        int val1=result.size();
        for(auto i=0;i<val1;i++)
        {
            int val=result.top();
            value=value+val*base;
            base=base*10;
            result.pop();
        }

        if(sign==-1)
        {
            value=value*-1;
        }
            
        
    }
};

int main()
{
    string value = "1234 hello world";
    unique_ptr<MyAtoi> ptr = make_unique<MyAtoi>(value);
    ptr->conversion();
}