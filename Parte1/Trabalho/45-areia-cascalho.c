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
    double  areia = 3769,
            cfino = 3446,
            cgrosso = 3967,

            m1_areia = 0.47,
            m1_cfino = 0.31,
            m1_cgrosso = 0.22,

            m2_areia = 0.23,
            m2_cfino = 0.53,
            m2_cgrosso = 0.24,

            m3_areia = 0.31,
            m3_cfino = 0.20,
            m3_cgrosso = 0.49;
    double E[ROWS][COLS] = {{m1_areia, m2_areia, m3_areia, areia},
                            {m1_cfino, m2_cfino, m3_cfino, cfino},
                            {m1_cgrosso, m2_cgrosso, m3_cgrosso, cgrosso}
    };

    gauss(E);
    reverse_substitution(E);

    return 0;
    // x_3 = 3
    // x_2 = 2
    // x_1 = 1
}
