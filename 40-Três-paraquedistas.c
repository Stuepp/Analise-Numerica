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
    double v = 7.91;
    double g = 9.81;
    // massas
    double m_1 = 69.74;
    double m_2 = 57.26;
    double m_3 = 48.07;
    // coeficiente de arrasto
    double c_1 = 11.47;
    double c_2 = 15.74;
    double c_3 = 19.94;

    double res_1 = - (m_1 * g - c_1 * v);
    double res_2 = - (m_2 * g - c_2 * v);
    double res_3 = - (m_3 * g - c_3 * v);

    double a_1 = -m_1;
    double a_2 = -m_2;
    double a_3 = -m_3;

    double t_1 = -1, t_2 = 1, t_3 = 0;
    double r_1 = 0, r_2 = -1, r_3 = 1;

    // Gauss input
    double E[ROWS][COLS] = {{a_1, r_1, t_1, res_1},
                            {a_2, r_2, t_2, res_2},
                            {a_3, r_3, t_3, res_3}};

    gauss(E);
    // x_1 = a
    // x_2 = R
    // x_3 = T
    reverse_substitution(E);

    return 0;
}
