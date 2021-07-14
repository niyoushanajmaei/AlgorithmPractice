//
// Created by Nioosha on 07-Jul-21.
//

#include <iostream>
#include<vector>
#define V 4
using namespace std;

//BFS on directed graph

void addEdge(vector<int> adj[],bool v[], int s, int d){
    adj[s].push_back(d);
};

void dfs(int i, vector<int> adj[], bool v[]){
    v[i] = true;
    cout << i << endl;
    for(int j=0;j<adj[i].size();j++){
        //cout <<j;
        //cout << adj[i][j];
        //cout << v[adj[i][j]]<<endl;
        if(v[adj[i][j]]==false){
            v[adj[i][j]] = true;
            dfs(adj[i][j],adj,v);
        }
    }
};

int main(){
    vector<int> *adj = new vector<int>[V];
    bool v[V];
    for (int i=0;i<V;i++){
        v[i] = false;
    }
    addEdge(adj,v,2,0);
    addEdge(adj,v,2,3);
    addEdge(adj,v,3,3);
    addEdge(adj,v,0,2);
    addEdge(adj,v,0,1);
    addEdge(adj,v,1,2);
    dfs(2,adj,v);
    return 0;
};
