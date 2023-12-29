#include<iostream>
#include<memory>
using namespace std;

class Node
{
    public:
        Node()
        {

        }
        int data;
        Node* next;




        
};
 

class linkedlist
{
    
    private:
        Node *head;
        Node *curr;

    public:
        linkedlist()
        {
            head=nullptr;
            curr=nullptr;
        }
        void InsertData(int value)
        {
            Node *new_node=new Node();
            if(head==nullptr)
            {
                head=new_node;
                curr=head;
                
                head->data=value;
                head->next=nullptr;
                
            }
            else
            {
                curr->next=new_node;
                new_node->data=value;
                new_node->next=head;
                curr=new_node;

            }
        }

        void display_data()
        {
            Node *ptr=head;
            while(ptr->next != nullptr)
            {
                cout<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }

        void loop_check()
        {
            Node *slow;
            Node *fast;
            slow=head;
            fast=head->next;

            while(slow != nullptr && fast != nullptr && fast->next !=nullptr)
            {
                cout<<slow->data<<"\t"<<fast->data<<endl;
                if(slow ==fast)
                {
                    cout<<"loop exist\n";
                    break;
                }
                slow=slow->next;
                fast=fast->next->next;

            }
            

        }
};
int main()
{
    unique_ptr<linkedlist>obj(new linkedlist());
    obj->InsertData(1);
    obj->InsertData(2);
    obj->InsertData(3);
    obj->InsertData(4);
    obj->InsertData(5);
    //obj->display_data();
    obj->loop_check();
}