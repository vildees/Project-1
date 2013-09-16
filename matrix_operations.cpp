#include <iostream>
#include <armadillo>
#include "time.h"

using namespace std;
using namespace arma;

int main(){
    int i, j, k, m;
    int n = 10000;

//    double ** A;

    mat B = randu<mat>(n,n);
    mat C = randu<mat>(n,n);
    mat A(n,n);

    clock_t start, finish;
    start = clock();

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            for (k=0; k < n; k++) {
                A(i,j) += B(i,k)*C(k,j);
            }
        }
    }

    finish = clock();

    cout << "Time needed for matrix multiplications: " << ( (finish - start) / (double) CLOCKS_PER_SEC ) << endl;
    return 0;
}
