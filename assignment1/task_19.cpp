#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;
class ThreeSum final
{
    private:
        vector<int>nums;
        vector<vector<int>>result;

    public:
        ThreeSum(vector<int>arr):nums(arr){}

        void calculate()
        {
            vector<int>copy_nums=nums;
            int first=0,second=0,third=0,sum=0;
            sort(copy_nums.begin(),copy_nums.end());

            for(auto i=0;i<copy_nums.size();i++)
            {
                first=copy_nums[i];
                second=copy_nums[i+1];
                third=copy_nums[copy_nums.size()-1];

                vector<int>row;

                while(second<third)
                {
                    sum=first+second+third;
                    if(sum==0)
                    {
                        row={first,second,third};
                        if(find(result.begin(),result.end(),row)==result.end())
                        {
                            result.push_back({first,second,third});
                            second=third+1;
                        }
                        row.clear();
                    }
                    else if (sum<0)
                    {
                        second++;
                    }
                    else
                    {
                        third--;
                    }
                    
                }
            }

            for(auto obj:result)
            {
                for(int obj1:obj)
                {
                    cout<<obj1<<"\t";
                }
                cout<<endl;
            }

            
            
        }
};
int main()
{
    vector<int> arr={-1,0,1,2,-1,-4};
    unique_ptr<ThreeSum>ptr=make_unique<ThreeSum>(arr);
    ptr->calculate();

    return 0;
}