#include<iostream>
#include<vector>
#include<array>
using namespace std;
void SpiralOutput(vector<vector<int>>&array);
int main()
{
  std::vector<std::vector<int>> my2DArray = {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15, 16}};

        SpiralOutput(my2DArray);
   

}

void SpiralOutput(vector<vector<int>>&array)
{
    //  for (const std::vector<int>& row : array) {
    //     for (int val : row) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //cout<<array.size();
    int top=0,down=array.size()-1,left=0,right=array.size()-1;
    bool flag=true;
    int count=0;
    while(top<down && left<right)
    {
        for(auto i=0;i<right;i++)
        {
            cout<<array[top][i]<<"\t";
        }
        top++;

        
       for(auto i=top-1;i<=down;i++)
       {
            cout<<array[i][right]<<"\t";
       }
       right--;

        for(auto i=down-1;i>=0;i--)
       {
            cout<<array[down][i]<<"\t";
       }
       //cout<<"down"<<down<<"\t"<<"top"<<top;

       for(int i=down-1;i>top;i--)
       {
            
            cout<<array[i][left]<<"\t";
       }
       down--;
       left++;

        count++;
    }
    
}
