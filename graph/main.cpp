#include "graph.cpp"
#include <iostream>
int main()
{
    Graph<int, int> g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 7);
    std::cout << "1-> ";
    for (auto &&el : g.getNeighbours(1))
    {
        std::cout << el << " -> ";
    }
    std::cout << std::endl;
    std::cout << g.getEdge(2, 3);
}