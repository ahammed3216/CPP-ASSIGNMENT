#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
class TrieNode
{
public:
    unordered_map<char, TrieNode *> node;
    bool isEndOfWord;
};

class Trie
{
private:
    TrieNode *head;
    TrieNode *root;
    vector<string> result;

public:
    Trie()
    {
        this->head = new TrieNode();
        this->root = nullptr;
    }

    bool startup(vector<string> arr1, vector<string> arr2)
    {
        for (auto i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] == "Trie")
            {
                result.push_back("null");
            }
            else if (arr1[i] == "insert")
            {
                this->insert(arr2[i]);
                result.push_back("null");
            }
            else if (arr1[i] == "search")
            {
                if (this->search(arr2[i]))
                    result.push_back("true");
                else
                    result.push_back("false");
            }
            else
            {
                if (this->prefix(arr2[i]))
                    result.push_back("true");
                else
                    result.push_back("false");
            }
        }
    }

    void insert(string word)
    {
        root = head;

        for (auto ch : word)
        {
            TrieNode *new_node = new TrieNode();

            if ((root->node).find(ch) == (root->node).end())
            {
                (root->node)[ch] = new_node;
                root = new_node;
            }
            else
            {
                root = (root->node)[ch];
            }
        }
        root->isEndOfWord = true;
    }

    bool search(string word)
    {
        int flag = 0;
        root = head;
        for (auto ch : word)
        {
            if (root->node.find(ch) != root->node.end())
            {
                root = root->node[ch];
            }
            else if (root->node.find(ch) == root->node.end())
            {
                flag = 1;
            }
        }
        if (root->isEndOfWord == true && flag == 0)
        {
            cout << "The word is present" << endl;
            return true;
        }
        else
        {
            cout << "the word is not present" << endl;
            return false;
        }
    }

    bool prefix(string word)
    {
        root = head;
        int flag = 0;
        for (auto ch : word)
        {
            if (root->node.find(ch) != root->node.end())
            {
                root = root->node[ch];
            }
            else
            {
                flag = -1;
            }
        }
        if (flag == 0)
        {
            cout << "The word prefix is found " << endl;
            return true;
        }
        else
        {
            cout << "The word prefix is not found " << endl;
            return false;
        }
    }

    void PrintResult()
    {
        for(const auto obj:result)
        {
            cout<<obj<<"\t";
        }
    }
};
int main()
{
    unique_ptr<Trie> ptr = make_unique<Trie>();
    vector<string> command = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<string> command_input = {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}};
    // ptr->insert("hai");
    // ptr->insert("haai");
    // ptr->search("hai");
    // ptr->search("ha");
    // ptr->prefix("ha");

    ptr->startup(command,command_input);
    ptr->PrintResult();
}