#include<iostream>
using namespace std;
class Innova
{
    private:
  
        int speed;

    public:
        Innova(int x)
        {
                this->speed=x;
        }

     virtual void get_speed(void)
    {

        cout<<"The maximum speed of the vehicle is 120 km/hr";
    }




};


class Crysta:public Innova
{
    private:
        int speed_new;

    public:

        Crysta(int x):Innova(x)
        {
            this->speed_new=x;
        }

        void get_speed()
        {
            cout<<"Speed of the vehicle is "<<this->speed_new;
        }

};

int main()
{
    Innova in(120);
    Crysta cr(90);

    Innova *ptr1;
    Crysta *ptr2;

    ptr1=&in;
    ptr2=&cr;

    ptr1->get_speed();
    cout<<endl;
    ptr1=&cr;
    ptr2->get_speed();


}
