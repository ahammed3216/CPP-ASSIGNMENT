#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;
class TimeClass
{
private:
    vector<unordered_multimap<string, unordered_multimap<string, int>>> commands_input;
    unordered_map<string, vector<pair<string, int>>> result;
    vector<string> commands;
    vector<string> main_result;

public:
    TimeClass(std::vector<std::unordered_multimap<std::string, std::unordered_multimap<std::string, int>>> arr1, vector<string> arr2)
    {
        this->commands_input = arr1;
        this->commands = arr2;
        cout << "null\t";
    }

    void set(map<string, pair<string, int>> data)
    {
        string main_key, second_key;

        int value;

        for (auto obj : data)
        {
            main_key = obj.first;
            second_key = obj.second.first;
            value = obj.second.second;
        }

        if (result.find(main_key) == result.end())
        {
            // result[main_key].push_back({second_key,value});
            // result[main_key]="hai";
            // result.insert({main_key,{second_key,value}});
            result[main_key].push_back(make_pair(second_key, value));
        }
        else
        {
            vector<pair<string, int>> row;
            row.push_back(make_pair(second_key, value));
            result[main_key] = row;
        }
        cout << "null\t";
    }

    string get(map<string, int> map)
    {
        string main_key, second_key;
        int new_time, old_time;

        for (auto obj : map)
        {
            main_key = obj.first;
            new_time = obj.second;
        }
        vector<pair<string, int>> row;
        row = result[main_key];

        for (auto obj : row)
        {
            second_key = obj.first;
            old_time = obj.second;
        }
        if (new_time >= old_time)
        {
            cout << second_key<<"\t";
            return second_key;
        }
        else
        {
            cout << "null";
            return "null";
        }
    }

    void ResultPrint()
    {
        for (const auto obj : main_result)
        {
            cout << obj << "\t";
        }
    }
};

int main()
{

    // Container
    std::vector<std::unordered_multimap<std::string, std::unordered_multimap<std::string, int>>> myContainer;

    // Add empty container
    myContainer.push_back({});

    // Add containers with key-value pairs
    myContainer.push_back({{"foo", {{"bar", 1}}},
                           {"foo", {{"bar", 1}}},
                           {"foo", {{"bar", 3}}},
                           {"foo", {{"bar2", 4}}},
                           {"foo", {{"bar", 4}}},
                           {"foo", {{"bar", 5}}}});

    vector<string> commands = {"TimeMap", "set", "get", "get", "set", "get", "get"};

    unique_ptr<TimeClass> ptr = make_unique<TimeClass>(myContainer, commands);

    ptr->set({{"foo", {"bar", 1}}});

    ptr->get({{"foo", 1}});

    ptr->get({{"foo", 3}});

    ptr->set({{"foo", {"bar2", 4}}});

    ptr->get({{"foo", 4}});

    ptr->get({{"foo", 5}});

 

    return 0;
}
