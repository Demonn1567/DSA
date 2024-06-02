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

    void addEdges(int src, int destn) {
        graph[src].push_back(new Edge(src,destn)); //directed graph
        //graph[destn].push_back(new Edge(destn, src)); //undirected graph
    }

    void printAllNeighbours() {
        for(auto edge : graph) {
            for(auto edges : edge) {
                cout<<edges->destn<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int start) {
        queue<int> q;
        bool isVisited[vertex];

        q.push(start);
        while(!q.empty()) {
            int val = q.front();
            q.pop();

            if(!isVisited[val]) {
                isVisited[val] = true;
                cout<<val<<" ";
            
            for(auto edge:graph[val]) {
                q.push(edge->destn);
            }
            }
        }
    }

    void DFS(int vertex, bool isVisited[]) {
        isVisited[vertex] = true;
        cout<<vertex<<" ";

        for(auto edge:graph[vertex]) {
            if(!isVisited[edge->destn]) {
                DFS(edge->destn, isVisited);
            }
        }
    } 

    void allPath(int vertex,int target,bool isVisited[],string path)
    {
        if(target == vertex)
        {
            cout<<path<<"-"<<target<<endl;
            return;
        }
        
        isVisited[vertex]= true;
        
        for(auto edge: graph[vertex])
        {
            if(!isVisited[edge->destn])
            allPath(edge->destn,target,isVisited,path+"-"+to_string(vertex));
        }
        
        isVisited[vertex]= false;
    }

    bool isCyclic(int v, bool isVisited[], bool* recStack) {
        if(!isVisited[v]) {
            isVisited[v] = true;
            recStack[v] = true;
        

        for(auto edge : graph[v]) {
            int destn = edge->destn;

            if(!isVisited[destn] && isCyclic(destn, isVisited, recStack)) {
                return true;
            }
            else if(recStack[destn]) {
                return true;
            }
        }
    }
        recStack[v] = false;
        return false;
    }




};


int main() {
    Graph g1(6);
    g1.addEdges(0,1);
    g1.addEdges(0,2);
    g1.addEdges(1,3);
    g1.addEdges(1,2);
    g1.addEdges(3,4);
    g1.addEdges(2,4);
    //g1.printAllNeighbours();
   // g1.BFS(0);
    //bool isVisited[g1.vertex];
    //g1.DFS(0, isVisited);
    bool isVisited[g1.vertex];
    bool* recStack;

    bool x = g1.isCyclic(0,isVisited, recStack);
    cout<<x;


    return 0;
}