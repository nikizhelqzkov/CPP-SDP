#include "graph.h"
template <class Vertex, class Weight>
void Graph<class Vertex, class Weight>::addVertex(const Vertex &v)
{
    vertices.insert(v);
    list[v];
}
template <class Vertex, class Weight>
void Graph<class Vertex, class Weight>::addEdge(const Vertex &v1, const Vertex &v2, Weight w)
{
    vertices.insert(v1);
    vertices.insert(v2);
    list[v1].insert(v2);
    edges.insert(std::make_pair(v1, v2), w);
}
template <class Vertex, class Weight>
bool Graph<class Vertex, class Weight>::hasVertex(const Vertex &v) const
{
    return vertices.contains(v);
}
template <class Vertex, class Weight>
bool Graph<class Vertex, class Weight>::hasEdge(const Vertex &v1, const Vertex &v2) const
{
    // return edge.contains(std::make_pair(v1, v2));
    return hasVertex(v1) && list[v1].contains(v2);
}
template <class Vertex, class Weight>
Weight &Graph<class Vertex, class Weight>::getEdge(const Vertex &v1, const Vertex &v2)
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge[std::make_pair(v1, v2)];
}
template <class Vertex, class Weight>
Weight Graph<class Vertex, class Weight>::getEdge(const Vertex &v1, const Vertex &v2) const
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge[std::make_pair(v1, v2)];
}
template <class Vertex, class Weight>
std::set<Vertex> &Graph<class Vertex, class Weight>::getNeighbours(const Vertex &v)
{
    if (!hasVertex(v))
    {
        std::invalid_argument("No vertex v");
    }
    return list[v];
}
