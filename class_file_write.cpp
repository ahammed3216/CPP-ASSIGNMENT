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

    

        ~Student()
        {
            cout<<"Destructor  is called\n";
        }
}obj1;

int main()
{

   Student obj2=obj1;
   cout<<"Copy constructor is defalulty called";

   Student *ptr=new Student[5]{{"123",30},{"unny ",3},{"navas ",13},{"ayyaril",5},{"kallur",7}};
   
    cout<<"checking data :"<<ptr->name<<endl;
    ofstream file;
    file.open("raw_student_data.txt",ios::out|ios::trunc);

    // for(auto i=0;i<5;i++)
    // {
    //     file<<(ptr+i)->name<<" "<<(ptr+i)->age<<"\n";
    // }
    // cout<<"File creation is completed";

   
for(auto i=0;i<5;i++)
{
    file.write((char *)(ptr+i),sizeof(*ptr));
}
    
        
    file.close();




   delete[] ptr;

    
}