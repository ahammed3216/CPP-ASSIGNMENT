#include <iostream>
using namespace std;
class Node
{
public:
    Node(int val) : data(val), leftptr(nullptr), rightptr(nullptr) {}
    int data;
    Node *leftptr;
    Node *rightptr;
};
class BinaryTree
{
public:
    Node *head;

public:
    BinaryTree()
    {
        this->head = nullptr;
    }

    void displayData(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        displayData(root->leftptr);
        cout << root->data << "\t";
        displayData(root->rightptr);
    }

    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        Node *left = lowestCommonAncestor(root->leftptr, p, q);
        Node *right = lowestCommonAncestor(root->rightptr, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        { // if both left and right are not null we found our lca
            return root;
        }
    }
};
int main()
{
    BinaryTree tree;
    tree.head = new Node(3);
    tree.head->leftptr = new Node(5);
    tree.head->rightptr = new Node(1);
    tree.head->leftptr->leftptr = new Node(6);
    tree.head->leftptr->rightptr = new Node(2);
    tree.head->leftptr->rightptr->leftptr = new Node(7);
    tree.head->leftptr->rightptr->rightptr = new Node(4);
    tree.head->rightptr->rightptr = new Node(8);
    tree.head->rightptr->leftptr = new Node(0);

    tree.displayData(tree.head);

    
    Node *result=tree.lowestCommonAncestor(tree.head,tree.head->leftptr->rightptr->leftptr,tree.head->leftptr->rightptr->rightptr);

    cout<<"\nThe lowest common ansector is "<<result->data;
    
}
