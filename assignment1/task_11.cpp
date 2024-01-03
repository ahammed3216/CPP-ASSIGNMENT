#include <iostream>
#include <memory>
using namespace std;



/*
 * @class-name : Node
 * @brief : Represting each node in the tree
 * @data members : data stores the vlues of the node and next stores the pointer of the next node
 */
class Node
{
public:
    Node()
    {
    }
    int data;
    Node *next;
};


/*
 * @class-name : Linked list
 * @brief : Represting Whole linked list connected using the Node class
 * @data-members:head and  current adress of the node
 * @data-function:insert data and display data
 */
class linkedlist
{

private:
    Node *head;
    Node *curr;

public:
    linkedlist()
    {
        head = nullptr;
        curr = nullptr;
    }
    /*
     * @func : Insert data into the Node and connecting in the binary tree
     * @return : void.only stores the data
     */
    void InsertData(int value)
    {
        Node *new_node = new Node();
        if (head == nullptr)
        {
            head = new_node;
            curr = head;

            head->data = value;
            head->next = nullptr;
        }
        else
        {
            curr->next = new_node;
            new_node->data = value;
            new_node->next = head;
            curr = new_node;
        }
    }

    /*
     * @func : display-data
     * @brief : it will display the data in the tree
     * @return :no return type , the value will displayed in the functin itself
     */
    void display_data()
    {
        Node *ptr = head;
        while (ptr->next != nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    /*
     * @func : getHeadAdress
     * @brief : To get the head adress outside the class
     * @return :return the node type adress
     */

    Node *getHeadAdress()
    {
        return head;
    }
};

bool loopCheck(Node *head);
int main()
{
    bool check = false;
    unique_ptr<linkedlist> obj(new linkedlist());
    obj->InsertData(1);
    obj->InsertData(2);
    obj->InsertData(3);
    obj->InsertData(4);
    obj->InsertData(5);
    // obj->display_data();
    check = loopCheck(obj->getHeadAdress());
    if (check == true)
    {
        cout << "Loop exists in the array ";
    }
    else
    {
        cout << "Loop not existing  in the array ";
    }
}

/*
 * @func-name : loop_check
 *@function_description:Function find the loop in the list
 * @return : void.only stores the data
 */
bool loopCheck(Node *head)
{
    Node *slow;
    Node *fast;
    slow = head;
    fast = head->next;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr)
    {
        cout << slow->data << "\t" << fast->data << endl;
        if (slow == fast)
        {
            cout << "loop exist\n";
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}