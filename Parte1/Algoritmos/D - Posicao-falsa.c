#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    return x * x - 2;
}

// Método da Posição Falsa
void false_position(double(*f)(double), double a, double b, int n) {
    double fa = f(a);
    double fb = f(b);

    if(fa * fb >= 0) {
        printf("O teorema de Bolzano não pode afirmar nada\n");
        return;
    } else {
        for (int i = 0; i < n; i++) {
            double x = (a * fb - b * fa) / (fb - fa);
            printf("x_%d = %.16f\n", i+1, x);
            double fx = f(x);

            if (fx == 0) {
                printf("Raiz encontrada. x = %.16f", x);
                return;
            }
            if (fa * fx < 0) {
                b = x;
                fb = fx;
            } else {
                a = x;
                fa = fx;
            }
        }
    }
}

int main() {
    double a_fp = 1.0;
    double b_fp = 2.0;
    int it_fp = 10;

    false_position(f, a_fp, b_fp, it_fp);
    return 0;
}
