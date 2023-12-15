#include<iostream>
#include<memory>
#include<stack>
using namespace std;

int diameter=0;
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
        int diameter;
        int root_diameter;
        int n1;
        int n2;
 
    public:
        
        binary_tree()
        {
            this->head=nullptr;
            diameter=0;
            root_diameter=0;
            n1=0;
            n2=0;
            
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


        int Height(Node* root)
        {
            if(root ==nullptr)
            {
                return 0;
            }
            int lh=Height(root->leftptr);
            int rh=Height(root->rightptr);
            diameter=max(diameter,lh+rh+1);
            root_diameter=lh+rh+1;

            return (1+max(lh,rh));

        }

        int Diamter()
        {
            
            Height(head);
            cout<<"\nroot diamter is :"<<root_diameter;
            return diameter;

        }

        int DepthRec(Node *root)
        {
            if(root==nullptr)
            {
                return 0;
            }
            else
            {
                int lDepth=DepthRec(root->leftptr);
                int RDepth=DepthRec(root->rightptr);

                if(lDepth>RDepth)
                {
                    return (lDepth+1);
                }

                else
                {
                    return (RDepth+1);
                }

            }
        }

        Node* lca(Node *root)
        {
            int value1=n1;
            int value2=n2;
            if(root ==nullptr)
            {
                return NULL;
            }

            if(((root->data) >n1) && ((root->data) >n2))
            {
                return lca(root->leftptr);
            }
            else if(((root->data) < n1 )&& ((root->data) <n2))
            {
                return lca(root->rightptr);
            }

            return root;

        }

        int lca_finder(int n1,int n2)
        {
            this->n1=n1;
            this->n2=n2;
            Node* value=lca(head);
            //cout<<value->data;
            return value->data;
            
        }
 
        
 
};
 
int main()
{

    int diamter=0,lca_value=0;
    unique_ptr<binary_tree>obj_ptr(new binary_tree());
 
    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);
    
    
 
    obj_ptr->DisplayData();
 
    obj_ptr->Depthvalue();

    
    diameter=obj_ptr->Diamter();
    cout<<"\nDiameter value is :"<<diameter;

    lca_value=obj_ptr->lca_finder(6,8);
    cout<<"\nThe lca of the given binary tree is :"<<lca_value;
 
    
 
}