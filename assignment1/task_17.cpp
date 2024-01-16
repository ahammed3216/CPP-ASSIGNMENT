#include<iostream>
#include<memory>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
class OriginDistance final
{
    private:
        vector<vector<int>>points;
        map<float,vector<int>>result;

    public:
        OriginDistance(vector<vector<int>>arr):points(arr){}

        void closestpoint(int k)
        {
            float dist=0;
            float kres;
            vector<float>subresult;
            for(auto obj:points)
            {
                dist=distance({obj[0],obj[1]});
                result.insert(make_pair(dist,obj));
                subresult.push_back(dist);

            }
            sort(subresult.begin(),subresult.end());
            kres=subresult.at(k-1);
            cout<<"The"<<k<<" th smaller distance is "<<kres<<endl;
            cout<<"The coordintates are : ";
            for(auto obj:result[kres])
            {
                cout<<obj<<"\t";
            }
        }
        float distance(vector<int>arr)
        {
            
            return (sqrt(arr[0]*arr[0] + arr[1]*arr[1]));
        
            
        }
};
int main()
{
    
    vector<vector<int>>points={{1,3},{-2,2}};
    unique_ptr<OriginDistance>ptr=make_unique<OriginDistance>(points);
    ptr->closestpoint(2);

}