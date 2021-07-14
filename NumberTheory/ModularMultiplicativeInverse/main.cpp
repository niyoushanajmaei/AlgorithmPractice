//
// Created by Nioosha on 08-Jul-21.
//

#include <iostream>

int mod_mult_inv(int a, int m);
int mod_mult_inv_r (int a, int m, int res);

using namespace std;

int main() {
    int a = 91;
    int m = 17;

    int x = mod_mult_inv(a,m);
    cout << x;
    return 0;
}

int mod_mult_inv(int a, int m) {
    return mod_mult_inv_r(a,m,1);
}

int mod_mult_inv_r (int a, int m, int res){
    cout << "a: "<<a << " m: "<< m << " res: " << res << endl;
    if (a%m == 1)
        return res;
    if (a<m){
        return mod_mult_inv_r(((m/a)+1)*a,m,(res * (m/a +1))%m);
    }
    return mod_mult_inv_r(a%m,m,res);
}