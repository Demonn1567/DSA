    //applying depth first search on a graph represented using adjacency lists
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
            graph.resize(vertex);
        }
        void addEdge(int src, int destn) {
            graph[src].push_back(new Edge(src, destn));
            graph[destn].push_back(new Edge(destn, src));
        }

        void DFS(int v, bool isVisited[]) {
            isVisited[v] = true;
            cout<<v<<" ";

            for(auto edge : graph[v]) {
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

    



    };

    int main() {
    Graph g1(5);

    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(1,0);
    g1.addEdge(1,3);
    g1.addEdge(4,3);
    g1.addEdge(4,1);

    bool isVisited[g1.vertex];

    

    /* for (int i = 0; i < g1.vertex; i++) {
        if (!isVisited[i]) {
            g1.DFS(i, isVisited);
        }
    } */
    //g1.allPath(0,3,new bool[g1.vertex]," ");

    return 0;
}
