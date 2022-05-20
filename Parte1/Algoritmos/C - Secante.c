#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    return x * x * x -2;
}

// Método da Secante
void secante(double (*f)(double), double x0, double x1, int n) {
    double fx0 = f(x0);
    double fx1 = f(x1);
    if (fx0 == fx1) {
        printf("Escolha outras estimativas iniciais\n");
    } else {
        for (int i = 0; i < n; i++) {
            double x2 = (x0 * fx1 - x1 * fx0)/(fx1 - fx0);

            fx0 = fx1;
            fx1 = f(x2);

            if (fx0 == fx1) {
                printf("x_%d = %.16f parou\n", i+2, x2);
            } else {
                printf("x_%d = %.16f\n", i+2, x2);
                x0 = x1;
                x1 = x2;
            }
        }
    }
}


int main() {

    // ATENÇÃO: x_2 = 1 iteracao! x_3 = 2 iterações! x_6 = 5 iterações!
    double x0_sec = 1;
    double x1_sec = 2;
    int it_sec = 5;

    secante(f, x0_sec, x1_sec, it_sec);
}
