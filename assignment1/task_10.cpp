#include <iostream>
#include <memory>
#include <stack>
using namespace std;

int diameter = 0;
/*
 * @class-name : Node
 * @brief : Represting each node in the tree
 * @data members : data stores the vlues of the node and next stores the pointer of the next node
 */
class Node
{
public:
    int data;

    Node *leftptr;
    Node *rightptr;

    Node(int data)
    {
        this->data = data;
        this->leftptr = nullptr;
        this->rightptr = nullptr;
    }

    void show_data()
    {
        cout << endl
             << data;
    }

    ~Node()
    {
        cout << endl
             << "\nDetructor is called !!";
    }
};
/*
 * @class-name : Binary Tree
 * @brief : Represting Whole linked list connected using the Node class
 * @data-members:head and  current adress of the node
 * @data-function:insert data and display data
 */
class binary_tree
{
private:
    Node *head;
    int diameter;
    int root_diameter;
    int n1;
    int n2;
    int small_element;
    int k_count;
    bool small_flag;

public:
    binary_tree()
    {
        small_element = 0;
        k_count = 0;
        small_flag = false;
        this->head = nullptr;
        diameter = 0;
        root_diameter = 0;
        n1 = 0;
        n2 = 0;
    }

     /*
     * @func : InsertData
     * @brief : function recieves the value and inserting the data into the list
     * @return:It returns nothing
     */
    void InsertData(int value)
    {
        cout << "at the insert section :" << value << endl;
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            cout << "\nhead value :" << value << endl;
            head = (new_node);
            head->leftptr = nullptr;
            head->rightptr = nullptr;
        }
        else
        {

            Node *temp = head;

            while (true)
            {
                if ((temp->data) < value)
                {
                    if ((temp->rightptr) == nullptr)
                    {
                        cout << endl
                             << "Data is added ath the left" << endl;
                        temp->rightptr = new_node;

                        return;
                    }
                    temp = temp->rightptr;
                }

                else if (temp->data > value)
                {
                    if (temp->leftptr == nullptr)
                    {
                        cout << endl
                             << "Data is added ath the right" << endl;
                        temp->leftptr = new_node;

                        return;
                    }
                    temp = temp->leftptr;
                }
                else
                {
                    cout << "In the else section";
                    delete new_node;
                    return;
                }
            }
        }
    }
  /*
     * @func : DisplayData
     * @brief : function  to display the data in the binary tree
     * @return:It returns nothing
     */
    void DisplayData()
    {
        stack<Node *> values;
        Node *temp = head;

        while (temp != nullptr || !values.empty())
        {
            while (temp != nullptr)
            {
                values.push(temp);
                temp = temp->rightptr;
            }

            temp = values.top();
            values.pop();
            cout << temp->data << " ";

            temp = temp->leftptr;
        }
    }

    // function to check whether the tree is balanced or not
    int balancecheck_optimized(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int lheight = balancecheck_optimized(root->leftptr);

        if (lheight == -1)
        {
            return -1;
        }
        int rheight = balancecheck_optimized(root->rightptr);

        if (rheight == -1)
        {
            return -1;
        }

        if (abs(lheight - rheight) > 1)
        {
            return -1;
        }

        return max(rheight, lheight) + 1;
    }

    // function to get the head adress of the binary tree
    Node *GetheadAdress()
    {
        return head;
    }

    int GetValue(Node *root)
    {
        return root->data;
    }
};

int main()
{

    int diamter = 0, lca_value = 0, depth_value = 0, bal_check = 0;
    unique_ptr<binary_tree> obj_ptr(new binary_tree());

    // Inserting Data into the tree
    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);

    cout << "\n\n---------Insert Data------------\n\n";
    obj_ptr->DisplayData();
    cout << "\n\n----------------------------------\n\n";

    cout << "\n\n----------Task 10 Answer------------\n\n";
    bal_check = obj_ptr->balancecheck_optimized(obj_ptr->GetheadAdress());
    if (bal_check == -1)
    {
        cout << "\nThe tree is not balanaced!!";
    }
    else
    {
        cout << "\nThe tree is  balanaced!!";
    }
    cout << "\n\n----------------------------------\n\n";
}