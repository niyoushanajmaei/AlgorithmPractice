//
// Created by Nioosha on 10-Jul-21.
//

#include <iostream>
#define V 9

//computes the shortest path using dijkstra's method
void shortest_path_dijkstra(int graph[V][V], int i);
//gets the node with the smallest path
int get_smallest(bool set[V], int dist[V]);
//updates the distances of the adjacent vertices of the node
void update_distances(int curr, int graph[V][V], int dist[V]);
//prints the result
void print_result(bool set[V], int dist[V]);
//initializes arrays set and dist
void initialize(bool set[V], int dist[V], int i);

using namespace std;

int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                               { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                               { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                               { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                               { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                               { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                               { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                               { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                               { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    shortest_path_dijkstra(graph, 0);

    return 0;
}

void shortest_path_dijkstra(int graph[V][V], int i) {
    int dist[V];
    //if we have already considered a vertex
    bool set[V];
    initialize(set,dist,i);

    update_distances(i,graph,dist);
    int c=1;
    while(c < V){
        int curr = get_smallest(set, dist);
        set[curr] = true;
        update_distances(curr,graph, dist);
        c++;
    }
    print_result(set,dist);
}

void initialize(bool set[V], int dist[V], int i) {
    //initializing set. at first only i-th vertex is in the set
    for (int j=0;j<V;j++){
        if(j==i)
            set[j] = true;
        else
            set[j] = false;
    }
    //initializing dist. at first all distances are inf and i-th vertex has distance 0
    for(int j=0;j<V;j++){
        if(j==i)
            dist[j] = 0;
        else
            dist[j] = INT16_MAX;
    }
}

void print_result(bool set[V], int dist[V]) {
    for (int i=0;i<V;i++){
        cout << "vertex: " << i << " distance: " <<dist[i]<<endl;
    }
}

void update_distances(int curr, int graph[V][V] , int dist[V]){
    for (int i=0;i<V;i++){
        if (graph[curr][i] != 0){
            //found an adjacent vertex, check if the current distance
            if(dist[curr] + graph[curr][i] < dist[i]){
                dist [i] = dist[curr] + graph[curr][i];
            }
        }
    }
}

int get_smallest(bool set[V], int dist[V]) {
    int min = INT16_MAX;
    int x = 0;
    for (int i=0;i<V;i++){
        if(set[i]==false && dist[i]<min){
            min = dist[i];
            x = i;
        }
    }
    return x;
}

