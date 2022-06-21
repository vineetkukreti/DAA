#include<iostream>
#include <list>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
bool Graph::isReachable(int s, int d){
    if (s == d)
        return true;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty()){
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if (*i == d)
                return true;
            if (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}
void isPath(Graph g,int u,int v){
    if(g.isReachable(u, v))
        cout<< "\nThere is a path from " << u << " to " << v;
    else
        cout<< "\nThere is no path from " << u << " to " << v;
}
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    isPath(g,1,3);
    isPath(g,3,1);
    cout<<"\nName: Vineet Kukreti\nRoll no: 78\nSec: N\nStd Id: 20011316";
    return 0;
}

