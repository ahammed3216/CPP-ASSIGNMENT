#include<iostream>
#include<vector>
#include<memory>
using namespace std;
template<class T>
class median
{
    private:
        vector<T>nums;
        T median_val;
        

    public:
        median(vector<T>arr):nums(arr){
            cout<<"object is created !!"<<endl;
              }

        void find_median()
        {
        
            if(nums.size()%2==0)
            { 
             this->median_val=static_cast<T>((nums[nums.size()/2])+(nums[(nums.size()/2) - 1]))/2;         
            }
            else
            {
                    this->median_val=nums[((nums.size()+1)/2)-1];
            }

            cout<<"The median value of the given array is :"<<this->median_val<<endl;
        }
        ~median()
        {
            cout<<"object is destroyed!!"<<endl;
        }
};
int main()
{

    vector<float>arr={1,2,3,4,5,6};
    unique_ptr<median<float>>ptr=make_unique<median<float>>(arr);
    ptr->find_median();

   

}