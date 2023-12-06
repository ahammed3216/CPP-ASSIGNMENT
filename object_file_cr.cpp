#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Student
{

    private:
        string name;
        int age;
    
    public:
        Student(string name="NULL",int age=0)
        {
            this->name=name;
            this->age=age;
        }

        void get_data()
        {

            cout<<"Enter the name of the student :";
            getline(cin,this->name);
            cout<<endl<<"Enter the name of the student :";
            cin>>this->age;
            
        }

        
        
};
int main()
{
    Student obj;
    obj.get_data();
    ofstream file;

    file.open("obj.txt",ios::out);

    file.write((char*)&obj,sizeof(obj));

    file.close();

    ifstream file1;
    file1.open("obj.txt",ios::in);
    file1.read((char*)&obj,sizeof(obj));


    file1.close();



}