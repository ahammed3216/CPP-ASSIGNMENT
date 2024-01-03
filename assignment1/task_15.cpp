#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,9> arr={1,8,6,2,5,4,8,3,7};
    int first=0;
    int last=arr.size()-1;
    int temp_area=0,max_area=-1;
    
    while(last>first)
    {
        //cout<<"the temp area is :"<<temp_area<<endl;
        temp_area=min(arr[last],arr[first]) *(last-first);
        if(temp_area>max_area)
        {
            max_area=temp_area;
        }
        if(arr[last]>arr[first])
        {
            first++;
        }
        else
        {
            last--;
        }

    }

    cout<<"\nThe maximum area getting from the water tank is :"<<max_area;
    
}