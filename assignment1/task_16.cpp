#include<iostream>
#include<memory>
#include<vector>

#include"class_headers.h"

using namespace std;

class KSmallElement
{
    private:
        int count;
        int result;
        
    public:

        KSmallElement()
        {
            this->count=0;
            this->result=0;
        }

        void elementFind(Node *root,int val)
        {
            

            if(root==nullptr || count>val )
            {
                return  ;

            }

            

            elementFind(root->leftptr,val);
            count++;
            if(count==val)
            {
                result=root->data;
                return;
            }
            elementFind(root->rightptr,val);

            

            
        }

        void printRes()
        {
            cout<<"The kth smallest element is "<<result;
        }

};
int main()
{

    int diamter = 0, lca_value = 0, depth_value = 0;

    unique_ptr<binary_tree> obj_ptr(new binary_tree());
    unique_ptr<KSmallElement>obj_ptr1=make_unique<KSmallElement>();

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

    obj_ptr1->elementFind(obj_ptr->GetheadAdress(),5);

    obj_ptr1->printRes();

  return 0;
}