#include<iostream>
using namespace std;
class Student final//cannot inherit this class
{
    private:    
        int age;
    
    public:
        void demo()
        {
            cout<<"hello world";
        }
};
// class teacher:public Student
// {

// };
class teacher
{
    private:
        int age;

    public:
         virtual void demo() final
        {
            cout<<"in the teacher class";
        }
         void check()
        {
            cout<<"check in the base class";
        }
};

class guest_teacher:public teacher
{
     private:
        int age1;

    public:
        //cannot override this function becuse it is termed as final in the base class
        //   void demo() 
        // {
        //     cout<<"in the teacher class";
        // }

         void check() 
        {
            cout<<"check in the child class";
        }


};
int main()
{
    guest_teacher obj;
    teacher obj1;
    obj1.check();

    obj.check();

}