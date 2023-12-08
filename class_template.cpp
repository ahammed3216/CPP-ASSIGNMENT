#include<iostream>
using namespace std;
template<class T>
class Add
{
    private:
        T var1;
        T var2;

    public:
        Add(T var1="demo",T var2="check")
        {
            this->var1=var1;
            this->var2=var2;
        }

        Add()
        {
            var1=0;
            var2=0;
        }

        T sum()
        {
            return this->var1 +this->var2;
        }


};
int main()
{
    Add<int>obj1(1,2);
   
    Add<string>obj2("hello","world");
    cout<<obj1.sum()<<endl;
    cout<<obj2.sum()<<endl;


}