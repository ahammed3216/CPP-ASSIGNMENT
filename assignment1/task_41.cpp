/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int subset(vector<int> &arr);
vector<vector<int>> result;
int main()
{
    vector<int> arr = {1, 2, 4};

    subset(arr);
}
int subset(vector<int> &arr)
{
    int count = 0;
    int n = arr.size();
    vector<int> subresult;
    count = pow(2, arr.size());
    cout << "The number of subset is :" << count<<endl;

    for (auto i = 0; i < count; i++)
    {
        for (auto j = 0; j < n; j++)
        {

            if (i & (1 << j))
            {
                // cout<<arr[j]<<"\t";
                subresult.push_back(arr[j]);
            }
        }
      
        result.push_back(subresult);
        subresult.clear();
    }
    for(const auto &num:result)
    {
        cout<<"{";
        for(auto i=num.begin();i!=num.end();i++)
        {
            cout<<*i<<" ";
        }
        cout<<"}"<<endl;

    }
    return 0;
}