//creating a graph using adjacency list and applying operations on it
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
    public:
    int src;
    int destn;

    Edge(int s, int d) {
        src = s;
        destn = d;
    }
};

class Graph {
    public:
    int vertex;
    vector<vector<Edge*> > graph;

    Graph(int v) {
        vertex = v;
        graph.resize(v);
    }
    void addEdge(int src, int destn) {
        graph[src].push_back(new Edge(src, destn));
        graph[destn].push_back(new Edge(destn, src));
    }

    void printAllNeighbours() {
        for(auto edge :graph) {
            for(auto edges:edge) {
                cout<<edges->destn<<" ";
            }
            cout<<endl;
        }
    }

    

};

int main() {
    Graph g1(7);

    g1.addEdge(0,1);
    g1.addEdge(0,4);
    g1.addEdge(1,4);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(1,3);

    g1.printAllNeighbours();


    return 0;
}