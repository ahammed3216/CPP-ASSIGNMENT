#include<iostream>
#include<vector>
#include<memory>
using namespace std;
template<class T>
class SortClass final
{
    private:
        vector<T>nums;
    public:
        SortClass(vector<T>arr):nums(arr){}

        void Sort()
        {
            int low=0,med=0,high=nums.size()-1;
            

            while(med<=high)
            {
                if (nums[med]==0)
                {
                    swap(nums[med],nums[low]);
                    low++;
                    med++;
                }
                else if(nums[med]==2)
                {
                    swap(nums[high],nums[med]);
                    high--;
                    med++;
                }
                else
                {
                    med++;
                }
                
            }


        }

        void display()
        {
            for(auto it =nums.begin();it!=nums.end();it++)
            {
                cout<<*it<<"\t";
            }

        }




};
int main()
{
    vector<int>arr={2,2,2,1,1,1};
    unique_ptr<SortClass<int>>ptr=make_unique<SortClass<int>>(arr);
    ptr->Sort();
    ptr->display();
}