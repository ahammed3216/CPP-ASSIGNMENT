#include<iostream>
int FindStep(int n);
using namespace std;
int main()
{
    cout<<"No of ways can :"<<FindStep(4);
}

int FindStep(int n)
{
    int result1=0,result2=0;
    if(n<=2)
        return n;
    
    else
    {
        result1= FindStep(n-1);
        result2=FindStep(n-2);
        return result1+result2;
    }
}
