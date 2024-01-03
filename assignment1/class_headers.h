#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*
 * @class-name : Node
 * @brief : Represting each node in the tree
 * @data members : data stores the vlues of the node and next stores the pointer of the next node
 */
class Node
{
    public:
            int data;
     
            Node* leftptr;
            Node* rightptr;
 
            Node(int data)
            {
                this->data=data;
                this->leftptr=nullptr;
                this->rightptr=nullptr;
                
            }
 
            void show_data()
            {
                cout<<endl<<data;
            }
 
            ~Node()
            {
                cout<<endl<<"\nDetructor is called !!";
            }
 
 
};
 
 /*
 * @class-name : Linked list
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
            small_element=0;
            k_count=0;
            small_flag=false;
            this->head=nullptr;
            diameter=0;
            root_diameter=0;
            n1=0;
            n2=0;
            
        }
            /*
        * @func : InsertData
        * @brief : function recieves the value and inserting the data into the list
        * @return:It returns nothing
        */
        void InsertData(int value)
        {
            cout<<"at the insert section :"<<value<<endl;
            Node* new_node=new Node(value);
            if(head ==nullptr)
            {
                cout<<"\nhead value :"<<value<<endl;
                head=(new_node);
                head->leftptr=nullptr;
                head->rightptr=nullptr;
            }
            else
            {
                
                Node* temp=head;
                
                while(true)
                {
                    if((temp->data) < value)
                    {
                        if((temp->rightptr) == nullptr)
                        {
                            cout<<endl<<"Data is added ath the right"<<endl;
                            temp->rightptr=new_node;
                            
                            return;
                        }
                        temp=temp->rightptr;
                    }
 
                    else if (temp->data > value)
                    {
                        if(temp ->leftptr == nullptr)
                        {
                            cout<<endl<<"Data is added ath the left"<<endl;
                            temp->leftptr=new_node;
                            
                            return;
                        }
                        temp=temp->leftptr;
                    }
                    else
                    {
                        cout<<"In the else section";
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
            stack<Node*>values;
            Node *temp=head;
            
            
            while(temp != nullptr || !values.empty())
            {
                while(temp != nullptr)
                {
                    values.push(temp);
                    temp=temp->rightptr;
                   
 
                }
 
                temp=values.top();
                values.pop();
                cout<<temp->data<<" ";
                
                temp=temp->leftptr;
                
 
            }
        }

        Node* GetheadAdress()
        {
            return head;
        }
 

};