#include<iostream>
using namespace std;
class FunctionPointer
{
    private:
        int x;
    public:
        void add(int a,int b)
        {
            x=a+b;
            cout<<"result is :"<<x;
        }
};

int sum(int a,int b);

int main()
{
    //function pointer for class
    FunctionPointer obj;
    void(FunctionPointer::*ptr)(int,int)=&FunctionPointer::add;
    (obj.*ptr)(10,20);

    //function pointer for normal function
    int (*ptr1)(int,int);
    ptr1=sum;
    int result=ptr1(20,40);
    cout<<"size is "<<sizeof(ptr1);

    return 0;
}
int sum(int a,int b)
{
    cout<<endl<<(a+b);
    return a+ b;

}