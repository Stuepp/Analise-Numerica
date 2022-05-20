#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    return x * x * x - 2;
}

// Método da bissecção
void bisection(double (*f)(double), double a, double b, int n) {
    if (f(a) * f(b) >= 0) {
        printf("Não é possível usar Bolzano para garantir a existencia de uma raiz em [%f, %f]", a, b);
    } else {
        for (int i = 0; i < n; i++) {
            double m = 0.5 * (a + b);
            printf("x_%d = %.16f\n", i+1, m);
            if (f(m) == 0) {
                printf("Você encontrou uma raiz. r = %.16f", m);
            } else {
                if (f(a) * f(m) < 0) {
                    b = m;
                } else {
                    a = m;
                }
            }
        }
    }
}



int main() {

    // intervalos iniciais:
    double a_bi = 0;
    double b_bi = 2;
    // numero de iterações:
    int it_bi = 20;

    bisection(f, a_bi, b_bi, it_bi);
}
