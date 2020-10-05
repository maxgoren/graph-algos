#include <iostream>

class Graph {
private: 
    struct node {
        char vert;
        struct node* next;
    };
    int numVerts;
    char name(int v);
    int index(char v);
    struct node *z;
    struct node **adjlist;
public:
   Graph(int N);
   ~Graph();
   void addEdge(char v, char u);
   void showList();
};

Graph::Graph(int N)
{
    int i;
    numVerts = N;
    z = new node;
    z->next = z;
    for (i = 1; i <= numVerts; i++)
      adjlist[i] = z;
}

Graph::~Graph()
{
    delete z;
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
   struct node* t;
   t = new node;;
   t->vert = v; t->next = adjlist[index(u)]; adjlist[index(u)] = t;
   t = new node;
   t->vert = u; t->next = adjlist[index(v)]; adjlist[index(v)] = t;
}

void Graph::showList()
{
    int i;
    struct node* t;
    for (i = 1; i <= numVerts; i++)
    {
        std::cout<<name(i)<<": ";
        for (t = adjlist[i]; t != z; t = t->next)
        {
          std::cout<<t->vert<<" ";
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
    demo.showList();
    return 0;
}