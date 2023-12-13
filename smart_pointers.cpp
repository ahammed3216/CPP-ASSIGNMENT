#include<iostream>
#include<memory>
using namespace std;

class Student
{
    private:
        int age;
    public:
        explicit Student(int x)
        {
                this->age=x;
        }
        
        void show_data()
        {
         
            cout<<"the value of the ptr is "<<age;
        }

    ~Student()
    {
        cout<<"\nDestructor is called";
    }
        
};
int main()
{

    
    //unique_ptr<Student>ptr(new Student(5));
    unique_ptr<Student>ptr=make_unique<Student>(42);

    //shared ptr
    shared_ptr<Student>ptr1(new Student(7));
    shared_ptr<Student>ptr4(new Student(7));
    shared_ptr<Student>ptr2 =ptr1;
    ptr4=ptr2;

    weak_ptr<Student>ptr3=ptr1;

    cout<<"the number of the shared objects to the weak pointer :"<<ptr3.use_count()<<endl;

    if(!ptr3.expired())
    {
        
       (ptr3.lock() )->show_data();

       
    }
    
    ptr3.reset();

    cout<<"\nthe number of the shared objects to the weak pointer after the reset :"<<ptr3.use_count()<<endl;

    ptr->show_data();

   

}