//
// Created by Nioosha on 08-Jul-21.
//

#include <iostream>
#include<time.h>

int mod_exp(int x, int y, int p);
int mod_exp_special_case(int x,int b, int y, int p);

using namespace std;

// x^y % p
int main() {
    int x = 123;
    int y = 10132;
    int p = 13;

    int m = mod_exp(x,y,p);

    cout << m;

    return 0;
}

int mod_exp(int x, int y, int p) {
    return mod_exp_special_case(x%p,x%p,y,p);
}

// when x < p
int mod_exp_special_case(int x,int b, int y, int p){
    if (y==1)
        return x;
    if (y%2==0)
        return mod_exp_special_case((x*b)%p,x*x,y/2,p);
    return mod_exp_special_case((x*b*b)%p,x*x,y/2,p);
}