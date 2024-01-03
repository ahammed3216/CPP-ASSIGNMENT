#include<iostream>
#include<memory>
#include<stack>
#include"class_headers.h"

using namespace std;
/*
 * @class-name : Node
 * @brief : Represting each node in the tree
 * @data members : data stores the vlues of the node and next stores the pointer of the next node
 */

int CheckBinaryTree(Node *root);
int main()
{


     unique_ptr<binary_tree>obj_ptr(new binary_tree());
    
    //Inserting Data into the tree
    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);

    int result=CheckBinaryTree(obj_ptr->GetheadAdress());
    if(result == 1)
    {
        cout<<"The tree is a binary search tree";
    }
    else
    {
        cout<<"The tree is not a binary search tree";
    }




}


int CheckBinaryTree(Node *root)
{
    if(root==nullptr || root->rightptr==nullptr || root ->leftptr ==nullptr)
    {
        return 1;
    }
    if(root->leftptr->data > root->data || root->rightptr->data < root->data)
    {
        return -1;
    }
    int right_check=CheckBinaryTree(root->leftptr);
    int left_check=CheckBinaryTree(root->rightptr);
    if(right_check == -1 || left_check == -1)
    {
        return -1;
    }

    return 1;
}