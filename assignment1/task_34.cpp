#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
class Merge
{
    private:
        vector<vector<int>>interval;
        vector<vector<int>>result;


    public:
        Merge(vector<vector<int>>arr):interval(arr){}

        void MergeInterval()
        {

            sort(interval.begin(),interval.end());
            int first=interval[0][0],second=interval[0][1];
            
            for(auto obj:interval)
            {
               if(obj[0]<=second)
               {
                if(obj[1]>second)
                    second=obj[1];
                
               }
               else
               {
                result.push_back({first,second});
                first=obj[0];
                second=obj[1];
                
                
               }
               
            }
            
        result.push_back({first,second});
        }
};
int main()
{
    vector<vector<int>>arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>arr1={{1,4},{4,5}};
    vector<vector<int>>arr2={{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>>arr3={{6,8},{1,9},{2,4},{4,7}};
    unique_ptr<Merge>ptr=make_unique<Merge>(arr2);
    ptr->MergeInterval();
}