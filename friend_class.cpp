#include<iostream>
using namespace std;

void func();
class Alpha

{
 
private:
	
      int a1;

 public:
	
      Alpha(int arg = 0)
	
     {
		a1 = arg;
	}
	
   
     friend class Beta;
     friend void func();

};



class Beta

{
 
private:

	int b1;

 public:

	Beta(int arg = 0)

	{
	b1 = arg;
	}


	int Sum()

	{
	    Alpha alpha_obj(3);


		int sum = alpha_obj.a1 + b1;
 

		return sum;
	
        }
    friend void func();

};



int main()
{
	Beta beta_obj(7);

	cout << "Sum is :" << beta_obj.Sum() << endl;
    func();

	return 0;
}


void func()
{
    Alpha obj(20);
    cout<<"Implementing the friemd function inside the main function "<<obj.a1;


}