/*Given an integer array nums return an array answer such that answer[i] is 
equal to the product of all the elements of nums except nums[i] You must write an
 algorithm that runs in O(n) time and without using the division operation*/

 #include<iostream>
 #include<array>
 using namespace std;
 int main()
 {
    array<int,4>arr={1,2,3,4};
    array<int,4>arr1;
    int sum=1,i=0,product;
    
    // for(auto i=0;i<arr1.size();i++)
    // {
    //     for(auto j=0;j<arr1.size();j++)
    //     {
    //         if(i==j)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             sum*=arr[j];
    //         }
    //     }
    //     arr1[i]=sum;
    //     sum=1;
    // }

    arr1[0]=1;
    for(i=1;i<arr.size();i++)
    {
        arr1[i]=arr1[i-1]*arr[i-1];

    }
    
    
    product=1;

    for(i=arr.size()-1;i>=0;i--)
    {
       arr1[i]=arr1[i]*product;
       product*=arr[i];

    }

    for(auto k=0;k<arr.size();k++)
    {
        cout<<arr1[k]<<"\t";
    }

 }