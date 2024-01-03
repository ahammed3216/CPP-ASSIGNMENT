#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int mincoins1(vector<int>&coins,int amount);
int main()
{
    int value=0,amount=0,result=0;
    vector<int>coins;
    cout<<"Enter the value of the denomination :\n";
    do
    {
        cout<<"Enter any negative value for stop  otherwise please continue :";
        cin>>value;
        if(value>=0)
        {
            coins.push_back(value);
        }
        


    }while(value != -1);

    for(auto i=coins.begin();i!=coins.end();i++)
    {
        cout<<*i<<"\t";
    }


    cout<<"\nEnter the amount to calculate :";
    cin>>amount;
    cout<<"the size of the vector is :"<<coins.size();
    result=mincoins1(coins,amount);
    cout<<"\nThe minimum number of coins to make the amount is "<<result;

  
}

/*
    * @func : mincoins
    * @brief : function reccursievely find the number of mic coins
    * @return : int value
    */
int mincoins1(vector<int>&coins,int amount)
{
    if(amount==0)
    {
        return 0;
    }
    int result=numeric_limits<int>::max();//to make the max limit condition
    
       
    for(int i=1;i<amount;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(coins[j]<=amount)
            {
                int subresult=mincoins1(coins,amount-coins[j]);
                if(subresult != numeric_limits<int>::max() )
                {
                    result=min(result,subresult+1);
                }
            }
        }
    }
    return result;
    
}
