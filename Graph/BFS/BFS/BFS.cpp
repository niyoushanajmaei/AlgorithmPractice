//
// Created by Nioosha on 07-Jul-21.
//
#include <iostream>;
#include<vector>;
#include <list>;
#define V 4
using namespace std;

//BFS on directed graph

void addEdge(vector<int> adj[],bool v[], int s, int d){
    adj[s].push_back(d);
};

void bfs(vector<int> adj[], bool v[], list<int> queue){
    while(queue.size()!=0){
        v[queue.front()] = true;
        cout << queue.front() << endl;
        for (int i=0;i<adj[queue.front()].size();i++){
            if(v[adj[queue.front()][i]]==false){
                queue.push_back(adj[queue.front()][i]);
            }
        }
        queue.erase(queue.begin());
    };
};

int main(){
    vector<int> *adj = new vector<int>[V];
    bool v[V];
    list<int> queue;
    for (int i=0;i<V;i++){
        v[i] = false;
    }
    addEdge(adj,v,2,0);
    addEdge(adj,v,2,3);
    addEdge(adj,v,3,3);
    addEdge(adj,v,0,2);
    addEdge(adj,v,0,1);
    addEdge(adj,v,1,2);

    queue.push_back(2);
    bfs(adj,v,queue);
    return 0;
};