#include<iostream>
#include<memory>
#include<vector>
#include<map>
using namespace std;
class Node
{
    public:
        int val;
        vector<Node*> neighbours;
        Node(int val)
        {
            this->val=val;
        }



};

class Graph
{
    public:
        map<Node*,Node*>visited;

        Node* clone(Node* root)
        {
            if(root==nullptr)
            {
                return nullptr;

            }
            if(visited.find(root)!= visited.end())
            {
                return visited[root];
            }
            Node* new_node=new Node(root->val);
            visited[root]=new_node;

            for (Node* &obj:root->neighbours)
            {
                new_node->neighbours.push_back(clone(obj));
            }

            return new_node;

        }

        void display(Node *root)
        {
            for (Node* &obj:root->neighbours)
            {
                cout<<obj->val<<"\t";
                //new_node->neighbours.push_back(clone(obj));
                display(obj);
            }
        }

};
int main()
{
    // Node* node1=new Node(1);
    // Node* node2=new Node(2);
    Graph G;
    unique_ptr<Node>node1=make_unique<Node>(1);
    unique_ptr<Node>node2=make_unique<Node>(2);
    unique_ptr<Node>node3=make_unique<Node>(3);
    unique_ptr<Node>node4=make_unique<Node>(4);


    node1->neighbours.push_back(node2.get());
    node1->neighbours.push_back((node4.get()));

    node2->neighbours.push_back((node1.get()));
    node2->neighbours.push_back((node3.get()));

    node3->neighbours.push_back((node2.get()));
    node3->neighbours.push_back((node4.get()));

    node4->neighbours.push_back((node1.get()));
    node4->neighbours.push_back((node3.get()));

    Node *clone_node=G.clone(node1.get());

    G.display(clone_node);

 
}