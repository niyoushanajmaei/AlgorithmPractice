//
//created by Nioosha on 25/07/2021
//

//solving n'th term,
//    F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
//Base Cases :
//    F(0) = 0, F(1) = 1, F(2) = 1

//using
//
// | F(n)   |  =  [ | 1 1 1 | ] ^ (n-2)   * | 1 |
//| F(n-1) |     [ | 1 0 0 | ]              | 1 |
//| F(n-2) |     [ | 0 1 0 | ]              | 0 |

#include <iostream>
#define N 3
using namespace std;
//the recursive function to calculate the exponent of a matrix
int mat_exp_r(int mat[N][N], int n, int op1[N][N], int op2[N][1]);
//multiplies an NxN matrix in a Nx1 matrix
void matmult(int op1[N][N], int op2[N][N], int res[N][N]);

int mat_exp(int mat[N][N], int n, int op2[N][1]);

void print_array(int mat[N][N]);

int main() {
    int n=5;
    int mat[N][N] = { {1,1,1},
                      {1,0,0},
                      {0,1,0}};
    int op2[N][1] = {{1},{1},{0}};
    int fn = mat_exp(mat,n-2,op2);

    cout<<n<<"-th term is: "<<fn;
    return 0;
}

int mat_exp(int mat[3][3], int n, int op2[N][1]) {
    int op1[N][N];
    int fn = 0;
    //setting op1 to the identity matrix
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)
                op1[i][j] = 1;
            else
                op1[i][j] = 0;
        }
    }
    fn = mat_exp_r(mat,n,op1,op2);
    return fn;
}

void matmult(int op1[N][N], int op2[N][N], int res[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += op1[i][k] * op2[k][j];
            }
        }
    }
}

int mat_exp_r(int mat[N][N], int n, int op1[N][N],int op2[N][1]) {
    if(n==0){
        int fn = 0;
        for (int i=0;i<N;i++){
            fn += op1[0][i] * op2[i][0];
        }
        return fn;
    }
    if(n%2==0){
        int a[N][N];
        matmult(mat,mat,a);
        return mat_exp_r(a,n/2,op1,op2);
    }
    int a[N][N];
    int b[N][N];
    matmult(mat,mat,a);
    matmult(mat,op1,b);
    return mat_exp_r(a,n/2,b,op2);
}

void print_array(int mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << mat[i][j] << " " ;
        }
        cout<<endl;
    }
}
