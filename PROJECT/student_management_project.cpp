#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string>
using namespace std;

class Student
{
    private:
        int admission_no;
        string name;
        int st_class;//studying class
        char gender;
        int marks;
    
    public:
        Student(int admission_no,string name,int st_class,char gender,int marks)
        {

            this->admission_no=admission_no;
            this->name=name;
            this->st_class=st_class;
            this->gender=gender;
            this->marks=marks;

            cout<<endl<<"Object is created ";
        }
        Student()
        {

        }

        void display();
        int get_admission_no();


}dummy;

void OptionSelection(void);
void InsertData(void);
void DisplayData(void);
void DeleteData(void);
void WriteFile(Student &obj);
void ReadFile();
void DeleteFile(Student &obj,int flag);

int Student::get_admission_no()
{
    return this->admission_no;
}

void Student::display()
{
    cout<<"Admission number :"<<this->admission_no<<endl;
    cout<<"Name of the student :"<<this->name<<endl;
    cout<<"Standard of studying :"<<this->st_class<<endl;
    cout<<"Gender :"<<this->gender<<endl;
    cout<<"Marks obtained :"<<this->marks<<endl;


}

vector<Student>StudentObjects;//Storage for the objects array of objects

int main()
{
        
        OptionSelection();
    

}

void OptionSelection(void)
{

    char option='0';
    while(option !='q' )
    {

        cout<<"\n\npress 1 to enter the detail of new student :"<<endl;
        cout<<"press 2 to see the detilas of the student :"<<endl;
        cout<<"press 3 to delete the detilas of the student :"<<endl;
        cout<<"press 4 to read the detilas of the student from file:"<<endl;
        cout<<"press q to quit the operation :"<<endl;

        cin>>option;

        if (option =='1')
        {
            InsertData();
        }
        else if(option =='2')
        {
            DisplayData();

        }
        else if(option =='3')
        {
            
            DeleteData();
        }
        else if (option=='4')
        {
            ReadFile();   
        }
        
        else if(option =='q')
        {
            cout<<endl<<"Quitting the application !!!";
            system("clear");
            break;
        }
        else
        {
            cout<<endl<<"Invalid option !!!"<<endl<<"Please try again !!!";
        }
        

    }
}

void InsertData(void)
{
    int admission_no,marks,st_class;
    string name;
    char gender;

   
    cout<<endl<<"Enter the admission no of the student :";
    cin>>admission_no;
    
    cin.ignore(); // to avoid the new line character
    cout<<endl<<"Enter the name   of the student :";
    getline(cin,name);
    
    
    cout<<endl<<"Enter the standard   of th student :";
    cin>>st_class;

    cout<<endl<<"Enter the Gender  of the student :";
    cin>>gender;

    cout<<endl<<"Enter the marks  of the student :";
    cin>>marks;

  
    Student obj1(admission_no,name,st_class,gender,marks);//demo object creation for saving
    StudentObjects.push_back(obj1);
    WriteFile(obj1);


 

}

void DisplayData(void)
{

    for(auto i=0;i<StudentObjects.size();i++)
    {
        StudentObjects[i].display();
        cout<<"\n\n\n---------";

    }

}

void DeleteData(void)
{
    int check,flag=-1;
    cout<<endl<<"Enter the admission number to delete :";
    cin>>check;

    vector<Student>::iterator i;
    for(vector<Student>::iterator i =StudentObjects.begin();i != StudentObjects.end();i++)
    {
            
           
            if((i->get_admission_no()) == check)
            { 
                StudentObjects.erase(i);
                cout<<endl<<"Student is found and sucessfully deleted";
                flag++;
                flag=0;
                break;
            }
           
    }
    if(flag==-1)
    {
        cout<<endl<<"the data is not found in the databse!!!..Please try with valid data";
    }
    

    
}


void WriteFile(Student &obj)
{
    ofstream file;
    file.open("student_data.txt",ios::out|ios::binary|ios::app);
    file.write(reinterpret_cast<char *>(&obj),sizeof(obj));
    file.close();
}


void ReadFile()
{
    ifstream file;
    file.open("student_data.txt",ios::in|ios::binary);

    for(vector<Student>::iterator i =StudentObjects.begin();i != StudentObjects.end();i++)
    {
            
           
          file.read((char*)(&dummy),sizeof(dummy));
          dummy.display(); 
    }
    


}

// void DeleteFile(Student &obj,int flag)
// {
//     ifstream file1;
//     ofstream tr_file,temp_file;
//     file1.open("student_data.txt",ios::in|ios::binary);
//     tr_file.open("student_data_trash.txt",ios::out|ios::binary|ios::app);
//     if(flag==-1)
//     {
//         temp_file.open("temp_data.txt",ios::out|ios::binary);

//         temp_file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
//     }
//     else
//     {
        

//         tr_file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
//     }

//     std::rename("temp.txt","student_data.txt");
    


// }