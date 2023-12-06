#include<iostream>
using namespace std;
class parent			        // Abstract class
{
public:
	  void show() 
     {

        cout<<"INside the base class";
     }	// pure virtual function

};

class boy : public parent
{
public:
	void show()
	{
		cout << "Brown Bun" << endl;
	}
};

class girl : public parent
{
public:
	void show()
	{
		cout << "Pink Bun" << endl;
	}
};

int main()
{
    boy obj1;
    girl obj2;
    parent *ptr;
    ptr=&obj1;

    ptr->show();
    ptr=&obj2;
    ptr->show();

    obj1.show();


}