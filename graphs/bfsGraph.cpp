#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
    public:
    int src;
    int destn;

    Edge(int s , int d) {
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
        graph.resize(vertex);
    }

    void addEdge(int src, int destn) {
        graph[src].push_back(new Edge(src, destn));
        graph[destn].push_back(new Edge(destn, src));
    }

    void printAllNeighbours() {
        for(auto edge :graph) {
            for(auto edges : edge) {
                cout<<edges->destn<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int start) {
        queue<int> q;
        bool visited[vertex];

        q.push(start);

        while(!q.empty()) {
            int val = q.front();
            q.pop();

            if(!visited[val]) {
                visited[val] = true;
                cout<<val<<" ";

                for(auto edge:graph[val]) {
                    q.push(edge->destn);
                }
            }
        }
    }

    bool cycleDetection(int start, int end, bool isVisited[],bool recStack) {
        
    }

};

int main() {
    Graph g1(7);    
    g1.addEdge(0,1);
    g1.addEdge(0,4);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(1,4);
    g1.addEdge(2,3);
    g1.addEdge(4,3);

    g1.BFS(0);


    return 0;
}