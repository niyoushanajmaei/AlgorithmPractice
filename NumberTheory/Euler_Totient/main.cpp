//
//Created by Nioosha on 11-07-2021
//

#include <iostream>
#include <math.h>
//computes the prime factors of n
int prime_factors(int n, int factos[],int sqrtn);
//computes the euler totient of n using the prime factors
int euler_totient(int n, int factors[], int c);

using namespace std;

int main() {
    int n = 10;
    int sqrtn = floor(sqrt(n));
    int factors[sqrtn];
    int num_fact = prime_factors(n, factors, sqrtn);
    cout << "number of prime factors of: "<< n << " is " << num_fact <<endl;
    cout << "euler totient: " << euler_totient(n,factors, num_fact);
    return 0;
}

//euler_totient = n * (Product)(1-1/p)
int euler_totient(int n, int factors[], int c) {
    int num = n;
    int denum = 1;
    for (int i=0;i<c;i++){
        num *= factors[i] -1;
        denum *= factors[i];
    }
    return num/denum;
}

//extracting prime factors upto sqrt(n)
//returns the number of prime factors
int prime_factors(int n, int factors[], int sqrtn) {
    int c = 0;
    for(int i=2;i<=sqrtn;i++){
        if (n%i == 0){
            factors[c] = i;
            do{
                n /= i;
            }while (n%i==0);
            c++;
        }
    }
    if (n!=1){
        factors[c] = n;
        c++;
    }
    return c;
}
