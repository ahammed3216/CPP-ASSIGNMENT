#include<iostream>
#include<fstream>
using namespace std;
class Student
{

    public:
        string name;
        int age;
    
    public:
        Student()
        {
            this->name="NULL";
            this->age=10;
            cout<<"Object type 1 is created\n";
        }

        Student(string name,int age)
        {
            this->name=name;
            this->age=age;
            cout<<"Object type2 is created\n";
        }

        // Student(Student &obj)
        // {
        //     this->name=obj.name;
        //     this->age=obj.age;
        //     cout<<"Object type3 is created\n";
        // }

    

        
}obj1;

int main()
{

 

   Student *ptr=new Student[5]();
   
  
    ifstream file;
    file.open("raw_student_data.txt",ios::in);



   
for(auto i=0;i<5;i++)
{
    file.read((char *)(ptr+i),sizeof(*ptr));
    cout<<(ptr+i)->name<<endl;
}
    
        
    file.close();




   delete[] ptr;

    
}