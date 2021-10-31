#include "kruskal.h"

using namespace std;

Graph::Graph(int n) {
    parent = new int[n];
    V = n;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::addEdge(int u, int v, double w) {
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
        return i;
    else
        // Else if i is not the parent of itself
        // Then i is not the representative of his set,
        // so we recursively call Find on its parent
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    int a = find_set(u);
    int b = find_set(v);
    parent[a] = b;
}

void Graph::kruskal() {
    int i=0, from, to;
    sort(G.begin(), G.end()); // increasing weight
    for (int i=0; i<G.size(); i++) {
        from = find_set(G[i].second.first);
        to = find_set(G[i].second.second);
        if (from != to) {
            union_set(from, to);
            //cout << "union set " << from << ", " << to << endl;
            //cout << "Now parent array:" << endl;

            T.push_back(G[i].second); // add to tree
        }
        
    }
    return;
}

void Graph::sortTree() {
    sort(T.begin(), T.end());
}

void Graph::printTree() {
    for (int i=0; i<T.size(); i++) {
        cout << T[i].first << " " << T[i].second << endl;
    }
}

void Graph::printcheck() {
    cout << "This is the Graph:" << endl;
    for (int i=0; i<G.size(); i++) {
        cout << "Edge: " << G[i].second.first << " to " << G[i].second.second << ", weight: " << G[i].first << endl;
    }
}

void Graph::printParent() {
    for (int i=0; i<V; i++) {
        cout << i << " ";
    }
    cout << "\n---------------------------------------------------\n";
    for (int i=0; i<V; i++) {
        cout << parent[i] << " ";
    }
}