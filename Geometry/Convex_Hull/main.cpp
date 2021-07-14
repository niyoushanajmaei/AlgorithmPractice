//
//Created by Nioosha 14-07-2021
//

//using Jarvis' Algorithm
//first select the left most point,i.e., the point with the smallest x
//at each iteration select the point that makes a counterclockwise orientation with all the remaining points
// O(n^2)

#include <iostream>
#include<math.h>
#include <list>
using namespace std;

struct Point{
    int x;
    int y;
};

void convexHull(Point points[],int n);
//gives 1 for clockwise and -1 for counterclockwise orientation
int orientation(Point p, Point q, Point r);

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    convexHull(points,sizeof(points)/sizeof(points[0]));
    return 0;
}

void convexHull(Point points[],int n){
    //find the left most point to start with, i.e. smallest x
    int min_x=INT16_MAX;
    int start;
    int current;
    list<int> hull;
    for(int i=0;i<n;i++){
        if (points[i].x < min_x){
            min_x = points[i].x;
            start = i;
        }
    }
    current = start;
    hull.push_back(current);
    bool found = false;
    do{
        found = false;
        for (int i=0;i<n && found ==false;i++){
            bool flag = true;
            if (i!=current) {
                for (int j = 0; j < n && flag == true; j++) {
                    if (j != current && j != i && orientation(points[current], points[i], points[j]) == -1) {
                        flag = false;
                    }
                }
                if (flag == true) {
                    current = i;
                    hull.push_back(current);
                    found = true;
                }
            }
        }
    }while(start!=current);

    //printing the result
    for(int i:hull){
        cout << "(" << points[i].x << ", " << points[i].y << ")"<<endl;
    }
}

int orientation(Point p, Point q, Point r) {
    // if the slop between 1 and 2 is smaller than the slope between 2 and 3, it's clockwise
    if ((r.y-q.y)*(q.x-p.x) - (q.y-p.y)*(r.x-q.x) >=0)
        //clockwise
        return 1;
    //counterclockwise
    return -1;
}
