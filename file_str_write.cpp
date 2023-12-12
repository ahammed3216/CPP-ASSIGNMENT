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

    ofstream file;
    file.open("demo.txt",ios::out| ios::trunc | ios::binary);
    Phone *ptr=new Phone();
    ptr->name="ahammed";

    file.write(reinterpret_cast<char*>(ptr),sizeof(*ptr));

    file.close();

}
