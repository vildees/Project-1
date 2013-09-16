#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

/* solve the one-dimensinal Poisson equation with Dirichlet boundary conditions */

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);

    double* a = new double[n];
    double* b = new double[n];
    double* c = new double[n];
    double* v = new double[n];
    double* b_tilde = new double[n];
    int i;
    double h = 1.0/(n+1.0);

    for (i=0; i<n; i++) {
        a[i] = -1;
        c[i] = -1;
        b[i] = 2;
        b_tilde[i] = h*h*100.0*exp(-10.0*i*h);
    }

    a[0] = 0;
    c[n-1] = 0;

    clock_t start, finish;
    start = clock();

    // forward substitution

    for (i=1; i<n-1; i++) {
        b[i+1] = b[i+1] - (a[i+1]/b[i])*c[i];
        b_tilde[i+1] = b_tilde[i+1] - (a[i+1]/b[i])*b_tilde[i];

    }

    // backward substitution

    v[n-2] = b_tilde[n-2] / b[n-2];
    for (i=n-2; i>0; i--){
        v[i-1] = (b_tilde[i-1] - c[i]*v[i]) / b[i-1];
    }

    finish = clock();
    cout << "Time: " << ( (double) (finish - start)/ (double) CLOCKS_PER_SEC) << endl;

    fstream outFile;
    outFile.open("data.dat", ios::out);

    outFile << n << endl;

    for (i = 1; i<n-1; i++) {
        outFile << v[i] << endl;
    }
    outFile.close();

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] v;
    delete[] b_tilde;

    return 0;
}
