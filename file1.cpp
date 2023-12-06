#include<iostream>
#include<fstream>
using namespace std;
int main()
{

    char ch;
    ofstream fout;
    ifstream fin;

    // fout.open("demo.txtt");
    // fout<<"hello world\n";
    // fout<<"hai world";
    // fout.close();

    // fin.open("demo.txtt");
    // fin>>ch;

    // while(!fin.eof())
    // {
    //     cout<<ch;
    //     fin>>ch;

    // }

    // fin.close();

    fout.open("demo.txt",ios::app);
    int pos=fout.tellp();
    cout<<"the position in the file appending is"<<pos;
    fout<<"This text is in the end of the file ";
    fout.close();
}