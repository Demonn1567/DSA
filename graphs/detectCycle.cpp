//detecting cycles in a directed graph
#include <iostream>
#include <vector>

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
}

bool cycleExist(int v, bool visited[], bool* recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (auto edge : graph[v]) {
            int destn = edge->destn;

            if (!visited[destn] && cycleExist(destn, visited, recStack)) {
                return true;
            } else if (recStack[destn]) {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

bool isCyclic() { //for directed graph
    bool* visited = new bool[vertex];
    bool* recStack = new bool[vertex];

    for(int i=0;i<vertex;i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i=0;i<vertex;i++) {
        if(!visited[i]&&cycleExist(i,visited,recStack))
        return true;
    }
    return false;
}

bool checkForCycle(int v, int parent, bool isVisited[]) { //for undirected graph
    isVisited[v] = true;
    for(auto edge : graph[v]) {
        if(!isVisited[edge->destn]) {
            if(checkForCycle(edge->destn,v,isVisited)) {
                return true;
        }
            else if(edge->destn!=parent) {
                return true;
            }
        }
    }
    return false;
}


};

int main() {
    Graph g1(5);
    /* g1.addEdge(1,0);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    //g1.addEdge(4,0);
    //g1.addEdge(0,2);
    g1.addEdge(2,1); */
    bool isVisited[g1.vertex];
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    //g1.addEdge(4,1);

    int x = g1.checkForCycle(1,-1,isVisited);
    cout<<x;

    return 0;
}