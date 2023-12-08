#include <iostream>
#include <thread>
using namespace std;


void threadFunction1();
void threadFunction2();

class ClassThreadFunction
{

    public:
      
       
        void t_fun1()
        {
            std::cout << "Hello from thread! Thread ID: " << std::this_thread::get_id() << std::endl;
            for(long int i=0;i<6500;i++)
            {
                cout<<"AUN\n";
            }
        }

        void t_fun2()
        {
            std::cout << "Hello from thread! Thread ID: " << std::this_thread::get_id() << std::endl;
            for(long int i=0;i<6500;i++)
            {
                cout<<"SMART\n";
            


        }



}
};
// Function to be executed in a separate thread
void threadFunction1() 
{
    std::cout << "Hello from thread! Thread ID: " << std::this_thread::get_id() << std::endl;
      for(long int i=0;i<6500;i++)
      {
        cout<<"h\n";
      }
}

void threadFunction2()
 {
    std::cout << "Hello from thread! Thread ID: " << std::this_thread::get_id() << std::endl;
      for(long int i=0;i<6500;i++)
      {
        cout<<"i\n";
      }
}

int main() 
{

    ClassThreadFunction obj;
  

    thread myThread1(threadFunction1);
    thread myThread2(threadFunction2);

    //FOR CLASS THREAD MENBER FUNCTION
    thread classThread1(&ClassThreadFunction::t_fun1,obj);
    thread classThread2(&ClassThreadFunction::t_fun2,obj);

    thread lamdaThread([] { cout<<"hai"; });
    thread lamdaThread1([] { cout<<"TECHNOLOGY"; });
    thread lamdaThread2([] { cout<<"SOLUTIONS"; });
    // Wait for the thread to finish execution
    myThread1.join();
    myThread2.join();

    classThread1.join();
    classThread2.join();

    lamdaThread.join();
    lamdaThread1.join();
    lamdaThread2.join();


    // Main thread message
    std::cout << "Hello from main! Thread ID: " << std::this_thread::get_id() << std::endl;
    

    return 0;
}
