#include<iostream>
#include<string>
using namespace std;
class Account
{
    private:
            long int account_number;
             int pin;
            long int mobile_no;
            string name;
            double balanace;

    public:

            Account(long int accnt=0, int u_pin=0,long int mobile=0,string name="NUll",double u_balance=0)
            {
                    account_number=accnt;
                    pin=u_pin;
                    mobile_no=mobile;
                    name=name;
                    balanace=u_balance;

            }
            Account(Account &user)
            {
                    account_number=user.account_number;
                    pin=user.pin;
                    mobile_no=user.mobile_no;
                    name=name;
                    balanace=user.balanace;

            }
          

            long int get_account_number()
            {

                return account_number;
            }

             int  get_pin()
            {


                return pin;
            }
            double get_balance()
            {
                return balanace;
            }

            void update_balance(int w_amonut)
            {

                balanace=balanace-w_amonut;
            }
            bool update_mobile_number(long mob)
            {

                mobile_no=mob;
                return true;
            }


};
int main()
{
    long int accnt,mob_no;
    short int pin;
    double w_amount;
    char option='0';
    bool status;
    Account user1,user2=(user1);

    
    cout<<"Account number of the user is "<<user2.get_account_number();
   
    cout<<"--------WLCOME TO AUN ATM SERVICES--------";
    cout<<endl<<"Enter your account number and pin :";
    cin>>accnt>>pin;

    
    
    if(user1.get_account_number()==accnt && user1.get_pin()==pin)
    {


        cout<<"User is authenticated";
        
        
        while(option !='q')
        {
            cout<<endl<<"\n\n-------SERVICES TO CLICK BELOW---------\n\n";
            
            cout<<endl<<"press 1 to BALANCE ENQUIRY"<<endl<<"press 2 for the money withdrawal"<<endl<<"Enter 3 to update mobile number";
            cin>>option;
            
            if(option =='1')
            {

                cout<<endl<<"Balance amount is"<<user1.get_balance();
            }
            else if(option=='2')
            {
                cout<<endl<<"ENter the amount to withdraw";
                cin>>w_amount;
                if(user1.get_balance() < w_amount)
                {
                    cout<<"\nYou have low balance in your account";
                }
                else
                {

                    cout<<endl<<"Processing your request!!!please take the money";
                    user1.update_balance(w_amount);
                    cout<<endl<<"the available balance in your account is "<<user1.get_balance();
                }


            }
            else if(option =='3')
            {
                    cout<<endl<<"Enter your mobile number :";
                    cin>>mob_no;
                    status=user1.update_mobile_number(mob_no);
                    if(status==true)
                        cout<<endl<<"your mobile number is updated sucessfully";
                    else
                        cout<<endl<<"failed to execute the process";



            }
            else if(option=='q')
                cout<<"quiting!!!";
            else
                cout<<"\nInvalid option";
        }
    }
    else
    {

        cout<<"The user is not authenticated";
    }
   

}