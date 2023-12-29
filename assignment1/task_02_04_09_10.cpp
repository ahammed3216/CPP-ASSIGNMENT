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
 
        int Depthvalue()
        {
            int depth_value=DepthRec(head);
            // stack<Node*>values;
            // int max=-1;
            // Node *temp=head;
            // int count=1;
            // bool flag=true;
            
            // while(temp != nullptr || !values.empty())
            // {
            //     flag=true;
            //     while(temp != nullptr)
            //     {
            //         flag=false;
            //         values.push(temp);
            //         temp=temp->rightptr;
            //         count++;
                   
 
            //     }
            //     if(flag==true)
            //     {
 
            //         cout<<"\nmaximum length is "<<count;
            //         if(count>max)
            //         {
            //             max=count;
            //         }
            //     }
 
            //     temp=values.top();
            //     values.pop();
            //     //cout<<temp->data<<" ";
                
            //     temp=temp->leftptr;
            //     count--;
 
            // }
 
            // cout<<"\nmaximum depth value of the tree is"<<max;
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

     

        int isBalanced(Node* root)
        {
            if(root == nullptr)
            {
                return 1;
            }

            int lh_height=Height(root->leftptr);
            int rh_height=Height(root->rightptr);

            if(abs(lh_height-rh_height) <= 1 && isBalanced(root->leftptr) && isBalanced(root->rightptr))
            {
                return 1;
            }

            return 0;
        }

        void balancecheck()
        {

           int value=balancecheck_optimized(head);
           if(value!= -1)
           {
            cout<<"The tree is balanced\n";

           }
           else
           {
            cout<<"\nthe tree is not balanced";
           }
        }

        int balancecheck_optimized(Node *root)
        {
            if(root==nullptr)
            {
                return 0;
            }

            int lheight=balancecheck_optimized(root->leftptr);

            if(lheight==-1)
            {
                return -1;
            }
            int rheight=balancecheck_optimized(root->rightptr);

            if(rheight ==-1)
            {
                return -1;
            }

            if(abs(lheight-rheight)>1)
            {
                return -1;
            }

            return max(rheight,lheight)+1;
            


        }

        void findMiddle(Node *slow,Node *fast)
        {
            if(fast==nullptr || slow==nullptr)
            {
                return ;
            }

            if(fast->rightptr ==nullptr && fast->leftptr==nullptr)
            {
                cout<<"Middle value is :"<<slow->data<<endl;
                return;
            }

            if(fast->leftptr->leftptr)
            {
                findMiddle(slow->leftptr,slow->leftptr->leftptr);
                findMiddle(slow->rightptr,fast->leftptr->leftptr);
            }
            else
            {
                findMiddle(slow->leftptr,fast->leftptr);
                findMiddle(slow->rightptr,fast->leftptr);
            }

        }

        void Middle()
        {
            findMiddle(head,head);
        }

        void FindSmallElement(int value)
        {
            KsmallElement(head,value);
            cout<<"the k th smallest element is :"<<this->small_element;
        }

        
        void KsmallElement(Node *root,int value)
        {

            if(root==nullptr || k_count>=value)
            {
                
                return ;
            }

           
            KsmallElement(root->leftptr,value);
            this->k_count++;
            if(this->k_count==value && small_flag==false)
            {
                this->small_element=root->data;
                this->small_flag=true;
                return;
            }
            

            return KsmallElement(root->rightptr,value);
            
            
            

        }
 
        
 
};
 
int main()
{

    int diamter=0,lca_value=0,depth_value=0;
    unique_ptr<binary_tree>obj_ptr(new binary_tree());
    
    //Inserting Data into the tree
    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);
    

    
    
    cout<<"\n\n---------Insert Data------------\n\n";
    obj_ptr->DisplayData();
    cout<<"\n\n----------------------------------\n\n";
 
    //Task 02 Answer
    cout<<"\n\n---------Task 02 Answer------------\n\n";
    depth_value=obj_ptr->Depthvalue();
    cout<<"\nDepth  value is :"<<depth_value;
    cout<<"\n\n----------------------------------\n\n";

    cout<<"\n\n----------Task 04 Answer------------\n\n";
    diameter=obj_ptr->Diamter();
    cout<<"\nDiameter value is :"<<diameter;
    cout<<"\n\n----------------------------------\n\n";
    
    cout<<"\n\n----------Task 09 Answer------------\n\n";
    lca_value=obj_ptr->lca_finder(6,8);
    cout<<"\nThe lca of the given binary tree is :"<<lca_value<<endl;
    cout<<"\n\n----------------------------------\n\n";

    cout<<"\n\n----------Task 10 Answer------------\n\n";
    obj_ptr->balancecheck();
    cout<<"\n\n----------------------------------\n\n";

    //obj_ptr->Middle();

    cout<<"\n\n----------Task 15 Answer------------\n\n";
    obj_ptr->FindSmallElement(4);
    cout<<"\n\n----------------------------------\n\n";

   
 
    
 
}