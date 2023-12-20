#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{

    ifstream ImageFile;
    ImageFile.open("image.jpg",ios::binary);
    if(!ImageFile)
    {
        cout<<"The image is not found";
    }
    else
    {
        cout<<"Image is found in the directory.";
     
    }
}