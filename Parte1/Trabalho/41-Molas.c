#include <stdio.h>
#include <math.h>
#define ROWS 3
#define COLS 4

void print_matrix(double array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.8f\t", array[i][j]);
        }
        printf("\n");
    }
}

void gauss(double E[ROWS][COLS]) {
    // percorrendo colunas
    for (int j = 0; j < COLS -2; j++) {
        // percorrenco a coluna j
        for (int i = j; i < ROWS; i++) {
            if (E[i][j] != 0) {
                if (i != j) {
                    // trocar linhas
                    double temp;
                    for (int k = 0; k < COLS; k++) {
                        temp = E[i][k];
                        E[i][k] = E[j][k];
                        E[j][k] = temp;
                    }
                }
                // o pivot (elemento ij de E) não é nulo
                // aqui vamos executar as operações em linha

                for (int m = j + 1; m < ROWS; m++) {
                    double a = -E[m][j] / E[j][j];
                    for (int n = j; n < COLS; n++) {
                        E[m][n] += a * E[j][n];
                    }
                }
                print_matrix(E);
                printf("\n");
                break;
            } else {
                if(i == ROWS + 1) {
                    printf("Sistema sem solução!\n");
                }
            }
        }
    }
}

void reverse_substitution(double E[ROWS][COLS]) {
    double answer[ROWS];
    for (int i = 0; i < ROWS; i++) {
        int d = ROWS - 1 - i;
        double b = E[d][COLS -1];
        for (int j = d + 1; j < COLS - 1; j++) {
            b -= E[d][j] * answer[j];
        }
        double xd = b / E[d][d];
        answer[d] = xd;

        printf("x_%d = %.16f\n", d+1, xd);
    }
}

int main() {
    double m1 = 4.22,
            m2 = 4.53,
            m3 = 2.81,
            k1 = 89.47,
            k2 = 52.36,
            k3 = 61.23,
            g = 9.81;

    // Gauss input
    double E[ROWS][COLS] = {{k1+k2, -k2, 0, m1*g},
                            {-k2, k2+k3, -k3, m2*g},
                            {0, -k3, k3, m3*g}
    };

    gauss(E);
    reverse_substitution(E);

    return 0;
}
