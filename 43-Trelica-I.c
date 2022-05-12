#include <stdio.h>
#include <math.h>
#define ROWS 6
#define COLS 7

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
        // x_1 = F1
        // x_2 = F2
        // x_3 = F3
        // x_4 = H2
        // x_5 = V2
        // x_6 = V3

        printf("x_%d = %.16f\n", d+1, xd);
    }
}

int main() {
    // Mudar os valores de alpha e beta, sem remover o M_PI/180
    double  alpha = 28 * M_PI/180,
            beta = 35 * M_PI/180,
            F = 2011;

    double E[ROWS][COLS] = { {-cos(alpha), 0, cos(beta), 0, 0, 0, 0},
                             {-sin(alpha), 0, -sin(beta), 0, 0, 0, F},
                             {cos(alpha), 1, 0, 1, 0, 0, 0},
                             {sin(alpha), 0, 0, 0, 1, 0},
                             {0, -1, -cos(beta), 0, 0, 0, 0},
                             {0, 0, sin(beta), 0, 0, 1, 0}
    };

    gauss(E);
    reverse_substitution(E);

    return 0;
}

// x_1 = F1
// x_2 = F2
// x_3 = F3
// x_4 = H2
// x_5 = V2
// x_6 = V3
