#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Phone
{
    public:
     string name;
};
int main()
{

    ifstream file;
    file.open("demo.txt",ios::in|  ios::binary);
    Phone *ptr=new Phone();
    

    file.read(reinterpret_cast<char*>(ptr),sizeof(*ptr));

    cout<<ptr->name;

    file.close();

}
