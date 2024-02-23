#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
    public:
    int src;
    int destn;
    int weight;

    Edge(int s, int d, int w) {
        src = s;
        destn = d;
        weight  = w;
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

    void addEdge(int src, int destn, int weight) {
        graph[src].push_back(new Edge(src, destn, weight));
        graph[destn].push_back(new Edge(destn, src, weight));
    }

    void dijkstra(int s) {
        bool visited[vertex];
        int distance[vertex];
        priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;

        for(int i=0;i<vertex;i++) {
            distance[i] = INT_MAX;
        }
        distance[s] = 0;
        pq.push(make_pair(s,0));
        while(!pq.empty()) {
            int node = pq.top().first;
            int dist = pq.top().second;
            cout<<dist<<" ";
            pq.pop();
            if(!visited[node]) {
                visited[node] = true;
                for(auto edge:graph[node]) {
                    int v = edge->destn;
                    int w = edge->weight;

                    if(dist +w < distance[v]) {
                        distance[v] = dist +w;
                        pq.push(make_pair(v, distance[v]));

                     }

                }

            }
        }

    }

};


int main() {
    Graph g1(5);
    g1.addEdge(0,1,3);
    g1.addEdge(0,4,8);
    g1.addEdge(0,3,7);
    g1.addEdge(4,3,3);
    g1.addEdge(1,3,4);
    g1.addEdge(1,2,1);
    g1.addEdge(3,2,2);

    g1.dijkstra(4);
        


    return 0;
}