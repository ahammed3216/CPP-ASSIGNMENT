/*Given the root of a binary tree,
return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

#include<iostream>
#include<memory>
#include"class_headers.h"
using namespace std;

/*
* @func : height
* @brief : to find the height of the tree defined in the binary tree class
* @return:It returns height of the tree as int value
*/
int binary_tree::Height(Node *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int rheight=Height(root->rightptr);
    int lheight=Height(root->leftptr);
    if(rheight>lheight)
    {
        return rheight+1;
    }
    else
    {
        return lheight+1;
    }
}
void LevelOrderTraversal(Node *root,int level);

int main()
{

    int height=0;
    unique_ptr<binary_tree>obj_ptr(new binary_tree());
    
    //Inserting Data into the tree
    obj_ptr->InsertData(5);
    obj_ptr->InsertData(3);
    obj_ptr->InsertData(7);
    obj_ptr->InsertData(1);
    obj_ptr->InsertData(4);
    obj_ptr->InsertData(6);
    obj_ptr->InsertData(8);

    height=obj_ptr->Height(obj_ptr->GetheadAdress());

    for(auto i=1;i<=height;i++)
    {
        LevelOrderTraversal(obj_ptr->GetheadAdress(),i);
    }

}
/*
* @func : LevelOrderTraversal
* @brief : Traverse the elements in the tree of the same level
* @return:It returns nothings in the function
*/
void LevelOrderTraversal(Node *root,int level)
{
    if(level==1)
    {
        cout<<root->data<<"\t";
    }
    else if(level >1)
    {
        LevelOrderTraversal(root->leftptr,level-1);
        LevelOrderTraversal(root->rightptr,level-1);
        
        
    }
    
}