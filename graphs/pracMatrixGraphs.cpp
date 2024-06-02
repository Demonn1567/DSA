#include <iostream>

using namespace std;

class Graph {
    public:
    int vertex;
    int** graph;

    Graph(int v) {
        vertex = v;

        graph = new int* [v];

        for(int i=0;i<v;i++) {
            graph[i] = new int[v];
        }
    }

    void addEdge(int src, int destn) {
        graph[src][destn] = 1; //directed graph

        graph[destn][src] = 1; //undirected graph
    }

    void printAllNeightbours() {
        for(int V=0;V<vertex;V++) {
            cout<<"Vertex - "<<V<<" :";
            for(int i=0;i<vertex;i++) {
                if(graph[V][i]==1) {
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(2,3);
    g1.addEdge(1,2);
    g1.printAllNeightbours();

    return 0;
}