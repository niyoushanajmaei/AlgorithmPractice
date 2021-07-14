//
//Created by Nioosha on 11-07-2021
//

#include <iostream>
using namespace std;

//checks if the two line segments have an intersection
bool intersect(int p1[2], int p2[2], int q1[2], int q2[2]);
//checks if two intervals are disjoint
bool disjoint_interval(int i1[2], int i2[2]);

int main() {
    //x and y coordinated of the beginning of segment 1
    int p1[2] = {1,1};
    //x and y coordinated of the end of segment 1
    int p2[2] = {10,1};
    //x and y coordinated of the beginning of segment 2
    int q1[2] = {1,2};
    //x and y coordinated of the end of segment 2
    int q2[2] = {10,2};
    intersect(p1,p2,q1,q2) ? cout << "Yes\n" : cout << "No\n";

    int a1[2] = {10, 0};
    int a2[2] = {0, 10};
    int b1[2] = {0, 0};
    int b2[2] = {10, 10};
    intersect(a1,a2,b1,b2) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
// the two segments intersect iff the x intervals and the y intervals of the segments aren't disjoint
bool intersect(int p1[2],int p2[2], int q1[2], int q2[2]){
    int x1[2] = {min(p1[0],p2[0]), max(p1[0],p2[0])};
    int x2[2] = {min(q1[0],q2[0]), max(q1[0],q2[0])};
    int y1[2] = {min(p1[1],p2[1]), max(p1[1],p2[1])};
    int y2[2] = {min(q1[1],q2[1]), max(q1[1],q2[1])};
    if (!disjoint_interval(x1,x2) && !disjoint_interval(y1,y2)){
        return true;
    }
    return false;
}

bool disjoint_interval(int i1[2], int i2[2]){
    if  (i1[1] < i2[0] || i2[1] < i1[0]){
        return true;
    }
    return false;
}
