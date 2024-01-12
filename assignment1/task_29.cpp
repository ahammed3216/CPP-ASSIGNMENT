#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
class Island final
{
private:
    vector<vector<string>> island;
    vector<vector<int>> visited;
    int value;

public:
    Island(vector<vector<string>> arr) : island(arr) {}

    void Startup()
    {
        vector<int> cord;
        bool flag = false;
        for (auto i = 0; i < island.size(); i++)
        {
            for (auto j = 0; j < island[0].size(); j++)
            {
                flag = false;
                cord.clear();
                cord.push_back(i);
                cord.push_back(j);
                countIsland(cord, flag);
            }
        }
    }

    void countIsland(vector<int> cord, bool &flag)
    {
        if ((find(visited.begin(), visited.end(), cord) == visited.end()))
        {
            vector<int> row;

            if (cord[0] >= island.size() || cord[1] >= island[0].size())
            {
                return;
            }
            string val = island[cord[0]][cord[1]];

            if (val == "1")
            {
                if (flag == false)
                {
                    value++;
                    flag = true;
                }
            }
            else if (val == "0")
            {
                visited.push_back(cord);
                return;
            }
            visited.push_back(cord);
            row.clear();
            int i = cord[0], j = cord[1] + 1;
            row.push_back(i);
            row.push_back(j);

            countIsland(row, flag);

            row.clear();
            i = cord[0] + 1, j = cord[1];
            row.push_back(i);
            row.push_back(j);

            countIsland(row, flag);

            return;
        }
    }

    void resultprint()
    {
        cout << "The count of the island is :" << value;
    }
};
int main()
{
    vector<vector<string>> arr = {
        {"1", "1", "1", "1", "0"},
        {"1", "1", "0", "1", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "0", "0", "0"}
    };

    vector<vector<string>>
        arr1 = {{"1", "1", "0", "0", "0"}, {"1", "1", "0", "0", "0"}, {"0", "0", "1", "0", "0"}, {"0", "0", "0", "1", "1"}

        };
    unique_ptr<Island> ptr = make_unique<Island>(arr1);

    ptr->Startup();

    ptr->resultprint();
}