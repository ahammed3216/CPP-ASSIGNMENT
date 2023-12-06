#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{

int j=0;
    string var1="hello world";
    char var2='d';

    for(int i=0;var1[i]!='\0';i++)
    {
            if(var1[i]==var2)
            {
                    for( j=i;j<var1.size()-1;j++)
                    {

                        var1[j]=var1[j+1];
                    }
                    var1[j]='\0';

            }


    }

    cout<<endl<<"var1: "<<var1;
    
   
    


}