#include<iostream>
using namespace std;
class Mutable
{
    private:
        mutable int data;
        int data1;

    public:
        Mutable(int x):data(x){}

        void update() const
        {
            
            data++; //when declare as const the updation is not possible
            cout<<"the data is "<<data<<endl;
        }

        void update1() 
        {
            data1++;
            data++; //when declare as const the updation is not possible
            cout<<"the data is "<<data<<endl;
        }
};
int main()
{
      Mutable obj(5);
     const Mutable obj2(4);
    // obj.update(); will cause error
    obj2.update1();
    obj.update();

     

}