//
//Created by Nioosha on 18-07-2021
//

#include <iostream>
#include<list>
#define V 5

void primMST(int graph[V][V]);
//returns the vertex not included yet and having minimum weight
int minWeight(int weight[V], bool included[V]);
//updates the weights of the adjacent vertices of a vertex
void update(int graph[V][V],int weight[V], int v);
//prints the result
void printMST(int weight[V], int parent[V]);

using namespace std;

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}

void primMST(int graph[5][5]) {
    bool included[V];
    int weight[V];
    int parent[V];
    int prev = -1;
    //initializing the arrays
    weight[0] = 0;
    included[0]= false;
    for (int i=1;i<V;i++){
        weight[i] = INT16_MAX;
        included[i] = false;
    }
    //performing the algorithm
    for (int i=0;i<V;i++){
        int min_v = minWeight(weight,included);
        included[min_v] = true;
        parent[min_v] = prev;
        update(graph,weight,min_v);
        prev = min_v;
    }
    //print the result
    printMST(weight,parent);
}

void printMST(int weight[V], int parent[V]) {
    for(int i=0;i<V;i++){
        if(parent[i]!=-1){
            cout << parent[i] << " -> " << i <<" : " << weight[i]<<endl;
        }
    }
}

void update(int graph[V][V], int weight[V], int v) {
    for(int j=0;j<V;j++){
        if(graph[v][j]!= 0 && graph[v][j]<weight[j]){
            weight[j] = graph[v][j];
        }
    }
}

int minWeight(int weight[V], bool included[V]) {
    int min = INT16_MAX;
    int min_v = -1;
    for (int i=0;i<V;i++){
        if(included[i]==false && weight[i]<min){
            min_v = i;
        }
    }
    return min_v;
}
