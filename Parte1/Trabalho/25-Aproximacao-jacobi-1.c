#include <iostream>
#define ROWS 3
#include <stdio.h>

void jacobi(double A[ROWS][ROWS], double B[ROWS], double chute[ROWS], int it) {
    double NEXT[ROWS];
    for (int k = 0; k < it; k++) {
        for (int i = 0; i < ROWS; i++) {
            double bi = B[i];
            for (int j = 0; j < ROWS; j++) {
                if (j != i) {
                    bi -= A[i][j] * chute[j];
                }
            }
            bi /= A[i][i];
            printf("x_%d^(%d) = %.16f\t", i+1, k+1, bi);
            NEXT[i] = bi;
        }
        printf("\n");
        // atualizar o chute
        for (int i = 0; i < ROWS; i++) {
            chute[i] = NEXT[i];
        }
    }
}

int main() {
    double A[ROWS][ROWS] = {{6.71, 3.64, 1.19},
                            {3.16, 9.88, 4.83},
                            {4.02, 2.17, -8.07}};
    double B[ROWS] = {0.82, -1.1, -3.07};

    double chute[ROWS] = {-1.87,4.25,4.31};
    int it = 18;

    jacobi(A, B, chute, it);
    return 0;
}
