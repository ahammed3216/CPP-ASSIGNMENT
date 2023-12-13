#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        cout<<"Destructor is called of node\n";
    }


};

class linkedList
{
private:
    Node *head;
    Node *present;

public:
    linkedList()
    {
        this->head = nullptr;
        this->present = nullptr;
    }

    void InsertData(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            present = new_node;
        }
        else
        {
            present->next = new_node;
            present = new_node;
        }
        cout << "Data added sucessfully" << endl;
    }

    void InsertData(int value, int pos)
    {
        int i = 0;
        Node *new_node = new Node(value);
        Node *temp, *prev;
        temp = head;

        if (pos == 0)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            while ((temp != nullptr))
            {

                if (i == (pos - 1))
                {

                    new_node->next = temp->next;
                    temp->next = new_node;
                }
                temp = temp->next;
                i++;
            }
        }
    }

    void InsertDataFront(int value)
    {
        Node *new_node = new Node(value);
        new_node->next = present;
        head = new_node;
        present = new_node;
    }

    void PrintData()
    {
        Node *temp;
        temp = head;
        while (temp != nullptr)
        {
            cout << "the data is " << temp->data << endl;
            temp = temp->next;
        }
    }

    void DeleteData(int value)
    {
        Node *temp;
        temp = head;
        if(head->data==value)
        {
           
            head=(temp->next);
        }
        else
        {
        while (temp != nullptr)
        {
            if ((temp->next)->data == value)
            {
              
                temp->next=(temp->next)->next;

            }
            temp = temp->next;
        }
        }
        
    }

    void FreePointer()
    {
        Node *temp,*prev;
        temp=head;
        while (temp != nullptr)
        {
            prev=temp->next;
            delete(temp);
            temp=prev;
            
        }
        

    }
};

int main()
{

    linkedList my_list;
    my_list.InsertData(5);
    my_list.InsertData(6);
    my_list.InsertData(7);
    my_list.InsertData(8, 0);
    // my_list.InsertDataFront(8);
    // my_list.InsertDataFront(9);
    // my_list.InsertDataFront(10);
    my_list.PrintData();
    my_list.DeleteData(8);
    cout<<"\nData printinf after the deletion"<<endl;
    my_list.PrintData();
    my_list.FreePointer();
}