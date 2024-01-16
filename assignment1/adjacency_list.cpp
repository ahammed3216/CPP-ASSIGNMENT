#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph
{
    private:
        int V;
        vector<list<int>>adjMatrix;
        vector<int>neighbours;
    
    public:
        Graph(int vertices):V(vertices),adjMatrix(vertices){};


        void addEdge(int u,int v)
        {
            adjMatrix[u].push_back(v);
            adjMatrix[v].push_back(u);//the value added because of undirected graph
            neighbours.push_back(u);

        }

        void display_matrix()
        {
            for(auto i=0;i<V;i++)
            {
                for(const auto &obj:adjMatrix[i])
                {
                    cout<<"->"<<obj<<"\t";
                }
                cout<<endl;
            }

        }



};
int main()
{
    Graph obj(3);
    obj.addEdge(0,1);
    obj.addEdge(1,2);
    obj.addEdge(0,2);
    
    

    obj.display_matrix();

    
}