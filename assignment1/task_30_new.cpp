/*You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell,
 1 representing a fresh orange, or 2 representing a rotten orange.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <queue>
using namespace std;
class RottenOranges
{
private:
    vector<vector<int>> oranges;
    vector<vector<int>> oranges_copy;
    vector<vector<int>> visited;
    queue<vector<int>> rotten_oranges;
    int fresh_count;
    int time;

public:
    RottenOranges(vector<vector<int>> arr)
    {
        this->oranges = arr;
        this->oranges_copy = arr;
        this->time = 0;
    }

    bool Isvalid(int x, int y)
    {
        if (x >= oranges.size() || y >= oranges.size() || x < 0 || y < 0)
            return false;

        else
            return true;
    }

    int Startup()
    {
        for (auto i = 0; i < oranges.size(); i++)
        {
            for (auto j = 0; j < oranges[0].size(); j++)
            {
                if (oranges[i][j] == 1)
                    this->fresh_count++;
                if (oranges[i][j] == 2)
                    rotten_oranges.push({i, j});
            }
        }

         vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!rotten_oranges.empty())
        {
            int size=rotten_oranges.size();

            for(auto k=0;k<size;k++)
            {
                int row=(rotten_oranges.front())[0];
                int col=(rotten_oranges.front())[1];
                rotten_oranges.pop();

                for(const auto obj:directions)
                {
                    int x_row=row+obj.first;
                    int x_col=col+obj.second;

                    if(Isvalid(x_row,x_col) && oranges[x_row][x_col]==1)
                    {
                        oranges[x_row][x_col]=2;
                        rotten_oranges.push({x_row,x_col});
                        fresh_count--;
                    }
                }
            }

            if(!rotten_oranges.empty())
            {
                time++;
            }
            
        }

        if(fresh_count != 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
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

    unique_ptr<RottenOranges> ptr = make_unique<RottenOranges>(arr);

    int result=ptr->Startup();

    if(result ==-1)
    {
        cout<<"It is not possible";
    }
    else
    {
        cout<<"The minimum time taken is "<<result;
    }

    return 0;
}