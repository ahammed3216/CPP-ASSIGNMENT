#include<iostream>
#include<vector>
using namespace std;


class Student
{

    private:
        int age;

    public:
        Student(int age)
        {
                this->age=0;
        }

        Student(const Student &obj)
        {
           
        }

        void show_data()
        {
            cout<<"The age is :"<<this->age;
        }

        ~Student()
        {
            cout<<endl<<"Destructor is called"<<endl;
        }
};

int main()
{

    vector<Student>objects;
    objects.emplace_back(12);
   objects.emplace_back(2);
  

}