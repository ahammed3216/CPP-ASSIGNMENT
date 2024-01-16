/*You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell,
 1 representing a fresh orange, or 2 representing a rotten orange.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
class RottenOranges
{
private:
    vector<vector<int>> oranges;
    vector<vector<int>> oranges_copy;
    vector<vector<int>> visited;
    int time;


public:
    RottenOranges(vector<vector<int>> arr)
    {
        this->oranges=arr;
        this->oranges_copy=arr;
        this->time=0;

    }

    int Startup()
    {
        bool flag=false;
        vector<int>row;
        for(auto i=0;i<oranges.size();i++)
        {
            this->time=0;
            for(auto j=0;j<oranges[0].size();j++)
            {
                    row.clear();
                    row.push_back(i);
                    row.push_back(j);
                    count(row,flag);
               
                
            }
        }

        for(auto i=0;i<oranges.size();i++)
        {
            this->time=0;
            for(auto j=0;j<oranges[0].size();j++)
            {
                    if(oranges[i][j]==1)
                    {
                        return -1;
                    }
               
                
            }
        }

        

    }

    void count(vector<int>cord,bool &flag)
    {
        vector<int>row;
        if(find(visited.begin(),visited.end(),cord)!=visited.end())
        {
            
            return ;
        }
        if(cord[0]>=oranges.size() || cord[1]>=oranges[0].size() || cord[0]<0 || cord[1]<0)
        {
            return;
        }
        

        if(oranges[cord[0]][cord[1]]==2)
        {
            if(flag==true)
                return;
            flag=true;           
        
        }
        else if(oranges[cord[0]][cord[1]]==1 && flag==true)
        {
            oranges[cord[0]][cord[1]]=2;        
            

        }
        else
        {
            return;
        }

        visited.push_back(cord);

        row.push_back(cord[0]+1);
        row.push_back(cord[1]);
        count(row,flag);//down
        
        row.clear();
        row.push_back(cord[0]);
        row.push_back(cord[1]+1);
        count(row,flag);//right

        row.clear();
        row.push_back(cord[0]-1);
        row.push_back(cord[1]);
        count(row,flag);//up

        row.clear();
        row.push_back(cord[0]);
        row.push_back(cord[1]-1);
        count(row,flag);//left
        time++; 

        

        
        


    }
};
int main()
{
    vector<vector<int>> arr =
        {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}

        };

    unique_ptr<RottenOranges>ptr=make_unique<RottenOranges>(arr);

    ptr->Startup();
}