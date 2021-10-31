#include <iostream>
#include <vector>

#define edge std::pair<int, int>

class Graph {
    private:
        std::vector<std::pair<double, edge> > G; // graph
        std::vector<edge> T; // mst
        int* parent;
        int V; // number of vertices/nodes in graph
    public:
        Graph(int n);
        void addEdge(int u, int v, double w);
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal();
        void sortTree();
        void printTree();
        void printcheck();
        void printParent();
};