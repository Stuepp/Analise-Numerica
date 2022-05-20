#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    return x * x * x - 2;
}

// Defina sua derivada
double derivadaf(double x) {
    return 3 * x * x;
}

// Método de Newton
void newton(double (*f)(double), double (*derivadaf)(double), double x0, int it) {
    double deriv = derivadaf(x0);
    if (deriv == 0) {
        printf("Escolha outra estimativa inicial.\n");
    } else {
        for (int i = 0; i < it; i++) {
            double x1 = x0 - f(x0)/derivadaf(x0);
            deriv = derivadaf(x1);
            if (deriv == 0) {
                printf("Parou na iteração x_%d, = %.16f\n", i+1, x1);
            } else {
                printf("x_%d = %.16f\n", i+1, x1);
            }
            x0 = x1;
        }
    }
}

int main() {

    double x0_new = 2;
    int it_new = 5;

    newton (f, derivadaf, x0_new, it_new);
    
    return 0;
}
