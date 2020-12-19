#include "graph.h"
template <class Vertex, class Weight>
Graph<Vertex, Weight>::Graph(std::vector<std::pair<Edges, Weight>> v)
{
    for (auto &&e : v)
    {
        addEdge(e.first.first, e.first.second, e.second);
    }
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addVertex(const Vertex &v)
{
    vertices.insert(v);
    list[v];
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addEdge(const Vertex &v1, const Vertex &v2, Weight w)
{
    vertices.insert(v1);
    vertices.insert(v2);
    list[v1].insert(v2);
    edge.insert({std::make_pair(v1, v2), w});
}
template <class Vertex, class Weight>
bool Graph<Vertex, Weight>::hasVertex(const Vertex &v) const
{
    return vertices.count(v) == 1;
}
template <class Vertex, class Weight>
bool Graph<Vertex, Weight>::hasEdge(const Vertex &v1, const Vertex &v2) const
{
    // return edge.contains(std::make_pair(v1, v2));
    return hasVertex(v1) && list.at(v1).count(v2) == 1;
}
template <class Vertex, class Weight>
Weight &Graph<Vertex, Weight>::getEdge(const Vertex &v1, const Vertex &v2)
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge[std::make_pair(v1, v2)];
}
template <class Vertex, class Weight>
Weight Graph<Vertex, Weight>::getEdge(const Vertex &v1, const Vertex &v2) const
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge.at(std::make_pair(v1, v2));
}
template <class Vertex, class Weight>
std::set<Vertex> &Graph<Vertex, Weight>::getNeighbours(const Vertex &v)
{
    if (!hasVertex(v))
    {
        std::invalid_argument("No vertex v");
    }
    return list[v];
}
