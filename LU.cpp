#include <iostream>
#include <armadillo>
#include <time.h>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);
    int i;
    int j;
    double h = 1.0/(n+1.0);

    mat A(n,n);     // specify size of array
    mat L, U, P;
    vec b_tilde(n);
    vec x(n);
    vec v(n);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
              if(i==j) {
                  A(i,j)= 2.0;
              }
              else if (i == j-1) {
                  A(i,j) = -1.0;
              }
              else if (i == j+1) {
                  A(i,j) = -1.0;
              }
              else {
                  A(i,j) = 0;
              }
        }
    }

    for (i=1; i<n-1; i++) {
        b_tilde(i) = h*h*100.0*exp(-10.0*i*h);
    }

    clock_t start, finish;
    start = clock();

    lu(L, U, P, A);

    x = inv(L)*b_tilde;
    v = inv(U)*x;

    //cout << v << endl;

    finish = clock();
    cout << ( (finish - start)/ (double) (CLOCKS_PER_SEC)) << endl;
    return 0;
}
