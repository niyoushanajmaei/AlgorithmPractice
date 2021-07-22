//
//Created by Nioosha on 19/07/2021
//

#include <iostream>
#define V 4
#include <list>
using namespace std;

struct Edge{
    int src;
    int dst;
    int weight;
    bool flag;
};

void kruksalMST(int graph[V][V]);

int getEdges(int graph[V][V], Edge edges[V*V/2]);

bool noCycle(int id[], Edge edge);

int minEdge(Edge edges[], int c);

int findId(int ids[], int v);

int main() {
    int graph[V][V] = {{0,10,6,5},
                       {0,0,0,15},
                       {0,0,0,4},
                       {0,0,0,0}};
    kruksalMST(graph);
    return 0;
}
//union is O(n). could be improved to O(log(n))
void kruksalMST(int graph[V][V]) {
    Edge edges[V*V/2];
    int c = getEdges(graph,edges);
    int id[V];
    list<Edge> MST;
    //cout<< "printing edges: "<<endl;
    for(int i=0;i<c;i++){
        //cout << edges[i].src << " -> "<<edges[i].dst<<endl;
        id[edges[i].src] = edges[i].src;
        id[edges[i].dst] = edges[i].dst;
    }
    //cout << "c : "<<c<<endl;
    for (int i=0;i<c;i++){
        int pos = minEdge(edges,c);
        //cout << "min is: "<< edges[pos].src << " -> " << edges[pos].dst <<endl;
        if (MST.size()==0 || noCycle(id,edges[pos])){
            MST.push_back(edges[pos]);
            id[findId(id,edges[pos].dst)] = findId(id,edges[pos].src);
        }
        edges[pos].flag = true;
    }
    for (Edge e:MST){
        cout << e.src <<" -> " << e.dst << " : " << e.weight<<endl;
    }
}

int minEdge(Edge edges[], int c) {
    int pos;
    int min = INT16_MAX;
    for (int i=0;i<c;i++){
        if (edges[i].flag == false && edges[i].weight < min){
            pos = i;
            min = edges[i].weight;
        }
    }
    return pos;
}
//O(n). could be improved to O(log(n))
bool noCycle(int id[], Edge edge) {
    int id_s = findId(id,edge.src);
    int id_d = findId(id,edge.dst);
    if(id_s == id_d){
        return false;
    }
    return true;
}

int findId(int ids[], int v){
    //cout << "id of " << v;
    while(ids[v]!=v){
        v = ids[v];
        //cout << " not : " << id;
    }
    //cout << " is : "<<v<<endl;
    return v;
}

int getEdges(int graph[V][V],Edge edges[V*V/2]) {
    int c =0;
    for (int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=0) {
                edges[c] = {i, j, graph[i][j],false};
                c++;
            }
        }
    }
    return c;
}
