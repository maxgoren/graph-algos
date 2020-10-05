#include <iostream>
#include <vector>


class Graph {
private:
   int numVerts;
   std::vector<char> Vertexes;
   std::vector<std::vector<int>> adjMatrix;
   char name(int v);
   int index(char v);
public:
   Graph(int N);
   void addEdge(char v, char u);
   void showMatrix();
};

Graph::Graph(int N)
{
    this->numVerts = N;
    adjMatrix.resize(N+1, std::vector<int>(N+1));
    for (auto vertadj : adjMatrix)
    {
        for (auto i : vertadj)
        {
            i = 0;
        }
    }
    for (auto i = 1; i <= N; i++)
    {
        Vertexes.push_back(name(i));
    }
}

char Graph::name(int v)
{
    return 'A' + v - 1;
}

int Graph::index(char v)
{
    return v - 'A' + 1;
}

void Graph::addEdge(char v, char u)
{
    adjMatrix[index(v)][index(u)] = 1; //Mark our edge
    adjMatrix[index(u)][index(v)] = 1; //mark reverse edge for undirected graph
}

void Graph::showMatrix()
{
    int i = 0;
    std::cout<<"  ";
    for (auto vert : Vertexes)
    {
        std::cout<<vert<<" ";
    }
    std::cout<<std::endl;
    for (i = 1; i <= numVerts; i++)
    {
        std::cout<<Vertexes[i-1]<<" ";
        for (auto l = 1; l <= numVerts; l++)
        {
         std::cout<<adjMatrix[i][l]<<" ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    Graph demo(5);
    demo.addEdge('A', 'E');
    demo.addEdge('A', 'B');
    demo.addEdge('B', 'D');
    demo.addEdge('B', 'E');
    demo.addEdge('C', 'D');
    demo.addEdge('C', 'E');
    demo.showMatrix();
    return 0;
}