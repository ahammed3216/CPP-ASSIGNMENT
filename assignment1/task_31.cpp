#include<iostream>
#include<memory>
#include<vector>
using namespace std;
class RotationSearch
{
    private:
        vector<int>nums;
        int result;

    public:
        RotationSearch(vector<int>arr):nums(arr){}

        void findVal(int target)
        {
            int middle,first=0,last=nums.size()-1;
            
            while(first<=last)
            {
                middle=(last+first)/2;

                if(nums[middle]==target)
                {
                    result=middle;
                    first=last+1;
                }
                else if(nums[first]>nums[last]  )//left sorted
                {
                    if(target<nums[middle] && target< nums[first])
                    {
                        first=middle+1;
                    }
                    else
                    {
                        last=middle-1;
                    }
                }
                else
                {
                    if(target>nums[middle])
                    {
                        first=middle+1;

                    }
                    else
                    {
                        last=middle-1;
                    }

                }
                
            }
            

        }
};
int main()
{
    vector<int>arr={4,5,6,7,0,1,2};
    unique_ptr<RotationSearch>ptr=make_unique<RotationSearch>(arr);
    ptr->findVal(0);

}