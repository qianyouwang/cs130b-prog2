#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
//#include "kruskal.h"
#include "kruskal.cpp"

#define coord pair<double, double>

using namespace std;


double dist(coord x, coord y) {
    //cout << "The coordinate of x: " << x.first << ", " << x.second << endl;
    //cout << "The coordinate of y: " << y.first << ", " << y.second << endl;
    //cout << "weight: " << sqrt( pow(x.first-y.first, 2) + pow(x.second-y.second, 2) ) << endl;
    return sqrt( pow(x.first-y.first, 2) + pow(x.second-y.second, 2) );
}


int main() {
    int n, m;

    cin >> n;
    vector<coord> coordinates;
    for (int i=0; i<n; i++) { // input coordinates vector
        double x, y;
        cin >> x >> y;
        coordinates.push_back(make_pair(x,y));
    }

    cin >> m;
    vector<edge> edges;
    if (m == 0) {
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) 
                edges.push_back(make_pair(i,j)); 
        }
    } else {
        for (int i=0; i<m; i++) { // input edges vector
            int v1, v2;
            cin >> v1 >> v2;
            edges.push_back(make_pair(v1,v2));
        }
    }
    //cout << "size of edges vector: " << edges.size() << " m= " << m << endl;

    vector<double> cost;
    for (int i=0; i<edges.size(); i++) { // calculate the cost for each edge
        int a = edges[i].first; int b = edges[i].second;
        cost.push_back( dist(coordinates[a], coordinates[b]) );
    }


    Graph g(n);
    for (int i=0; i<edges.size(); i++) {
        g.addEdge(edges[i].first, edges[i].second, cost[i]);
    }

    g.kruskal();
    //g.printcheck();
    g.sortTree();
    g.printTree();
    return 0;
}