#include<iostream>
using namespace std;
class Mutable
{
    private:
        mutable int data;

    public:
        Mutable(int x):data(x){}

        void update() const
        {
            data++; //when declare as const the updation is not possible
            cout<<"the data is "<<data<<endl;
        }
};
int main()
{
     const Mutable obj(5);
     Mutable obj2(4);
    // obj.update(); will cause error
    obj2.update();
    obj.update();

     

}