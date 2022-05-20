#define ROWS 4
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
    double A[ROWS][ROWS] = {{14.98,-4.94, -4.86, 3.43},
                            {-0.75, -7.36, -1.58, -3.27},
                            {4.65, -1.88, -12.79, -4.51},
                            {3.48, 3.34, -4.94, -13.5}};
    double B[ROWS] = {-2.24, -1.4, -1.86, -4.41};

    double chute[ROWS] = {-2.18, 0.45, -0.86, 2.88};
    int it = 16;

    jacobi(A, B, chute, it);
    return 0;
}
