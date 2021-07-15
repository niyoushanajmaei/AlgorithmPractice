//
//Created by Nioosha 15-07-2021
//

#include <iostream>
#include <list>
#include <math.h>
using namespace std;

void eratosthenes(int n);

int main() {
    int n=10;
    eratosthenes(n);
    return 0;
}

void eratosthenes(int n) {
    int sn = floor(sqrt(n))+1;
    //true means prime
    bool prime[n+1];
    for (int i=0;i<=n;i++){
        prime[i] = true;
    }
    for (int i=2;i<sn;i++){
        if (prime[i]==true){
            for (int j=2;j<=n/i;j++){
                prime[j*i] = false;
            }
        }
    }
    //print the result
    for (int i=2;i<=n;i++){
        if(prime[i]==true)
            cout << i << ", ";
    }
}
