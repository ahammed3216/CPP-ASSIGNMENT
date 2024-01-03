#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
class Coin
{

    private:
        int count;
        int left_amount;
    public:
        Coin()
        {
            count=0;
            left_amount=0;

        }

        int Exchange(vector<int>&data, int value,int amount)
        {
            int max=0;
            auto max_iterator=max_element(data.begin(),data.end());
            if(amount > value)
            {
                
                if(max_iterator != data.end())
                {
                    max=*max_iterator;
                }
                count+=(amount/max);
                amount=amount%max;
                data.erase(max_iterator);
            }
            else
            {

            }

        }

};
int main()
{

}