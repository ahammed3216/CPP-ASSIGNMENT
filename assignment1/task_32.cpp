#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
class CombinationSum final
{
    private:
        vector<int>nums;
        vector<vector<int>>result;
        int target;
        vector<int>subres;

    public:
        CombinationSum(vector<int>arr,int bal)
        {
            this->nums=arr;
            this->target=bal;
        }

        void sum()
        {
            find_sum(target);
        }

        void find_sum(int bal)
        {
            if(bal==0)
            {
                int sum=std::accumulate(subres.begin(),subres.end(),0);
                if(sum==target)
                {
                    sort(subres.begin(),subres.end());
                    if(find(result.begin(),result.end(),subres)==result.end())
                        result.push_back(subres);
                    subres.clear();//note
                    return;
                }
                subres.pop_back();
                return ;
            }
            if(bal>target)
            {
                return ;
            }
            
            for(auto const obj:nums)
            {
                if(bal-obj>=0)
                {
                    subres.push_back(obj);
                    
                    find_sum(bal-obj);
                }
                else
                {
                    if(!subres.empty())
                        subres.pop_back();
                    return;
                }
            }

            
        }
};
int main()
{
    vector<int>arr={2,3,6,7};
    vector<int>arr1={2,3,5};
    int target=8;
    unique_ptr<CombinationSum>ptr=make_unique<CombinationSum>(arr1,target);
    ptr->sum();
}