#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<memory>

using namespace std;
class TrieClass
{
    private:
        vector<vector<string>>arg;
        vector<string>commands;
       
    public:
        TrieClass(vector<vector<string>>arr):arg(arr){}

        void Set()
        {
            commands=arg[0];
        }
};
int main()
{
    vector<vector<string>>arr={{},{{"foo", "bar", 1}, {"foo", 1}, {"foo", 3}, {"foo", "bar2", 4}, {"foo", 4}, {"foo", 5}}};
    unique_ptr<TrieClass>ptr=make_unique<TrieClass>(arr);
}