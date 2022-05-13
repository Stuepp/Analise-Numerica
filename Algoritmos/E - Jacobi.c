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
    double A[ROWS][ROWS] = {{4, 1, -1},
                            {-1, 3, 1},
                            {1, -1, 5}
    };

    double B[ROWS] = {5, 6, 4};

    double chute[ROWS] = {0, 0, 0};

    int it = 5;
    jacobi(A, B, chute, it);
    return 0;
}
