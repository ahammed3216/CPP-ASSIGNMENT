#include<iostream>
#include<memory>
#include<stack>
using namespace std;
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


class binary_tree
{
    private:
        Node *head;

    public:
        
        binary_tree()
        {
            this->head=nullptr;
            
        }

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
                            cout<<endl<<"Data is added ath the left"<<endl;
                            temp->rightptr=new_node;
                            
                            return;
                        }
                        temp=temp->rightptr;
                    }

                    else if (temp->data > value)
                    {
                        if(temp ->leftptr == nullptr)
                        {
                            cout<<endl<<"Data is added ath the right"<<endl;
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

        void Depthvalue()
        {
            stack<Node*>values;
            int max=-1;
            Node *temp=head;
            int count=1;
            bool flag=true;
            
            while(temp != nullptr || !values.empty())
            {
                flag=true;
                while(temp != nullptr)
                {
                    flag=false;
                    values.push(temp);
                    temp=temp->rightptr;
                    count++;
                   

                }
                if(flag==true)
                {

                    cout<<"\nmaximum length is "<<count;
                    if(count>max)
                    {
                        max=count;
                    }
                }

                temp=values.top();
                values.pop();
                //cout<<temp->data<<" ";
                
                temp=temp->leftptr;
                count--;

            }

            cout<<"\nmaximum depth value of the tree is"<<max;
        }

        

};

int main()
{
    unique_ptr<binary_tree>obj_ptr(new binary_tree());

    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);
    obj_ptr->InsertData(9);
    obj_ptr->InsertData(10);

    obj_ptr->DisplayData();

    obj_ptr->Depthvalue();


    

}