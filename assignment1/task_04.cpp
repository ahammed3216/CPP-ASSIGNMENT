#include <iostream>
#include <memory>
#include <stack>
using namespace std;

int diameter = 0;
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

    //Insert funtion to instert the values in the bibary tree
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

    //function to diokay the values in the binary tree
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

    //It is the height function of the dimeter
    int Height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lh = Height(root->leftptr);
        int rh = Height(root->rightptr);
        diameter = max(diameter, lh + rh + 1);//it is the condition for finding the dimerter of the tree
        root_diameter = lh + rh + 1;//it is the final diameter of the tree will be the dimater of the root node

        return (1 + max(lh, rh));
    }

    //function to get the head adress of the binary tree
    Node *GetheadAdress()
    {
        return head;
    }
};

int main()
{

    int diamter = 0, lca_value = 0, depth_value = 0;
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

    cout << "\n\n----------Task 04 Answer------------\n\n";
    diameter = obj_ptr->Height(obj_ptr->GetheadAdress());
    cout << "\nDiameter value is :" << diameter;
    cout << "\n\n----------------------------------\n\n";
}