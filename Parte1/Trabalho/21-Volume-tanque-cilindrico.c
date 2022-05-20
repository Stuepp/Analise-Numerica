#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    double v = 42.13,
    l = 5.27,
    r = 3.78,
    pi = M_PI,

    k = 0.5 * pi * pow(r, 2),
    arcoseno = pow(r, 2) * asin(x/r),
    raiz = x * sqrt(pow(r, 2) - pow(x, 2));

    return v - (l * (k - arcoseno - raiz));
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
    // BISSECÇÃO:
    printf("BISSECÇÃO:\n\n");
    // intervalos iniciais:
    double a_bi = 0;
    double b_bi = 3.78;
    // numero de iterações:
    int it_bi = 12;

    bisection(f, a_bi, b_bi, it_bi);
    printf("-------------------------------\n");

    // SECANTE:
    // ATENÇÃO: x_2 = 1 iteracao! x_3 = 2 iterações! x_6 = 5 iterações!
    printf("SECANTE:\n\n");
    double x0_sec = 0.85;
    double x1_sec = 3.61;
    int it_sec = 5;

    secante(f, x0_sec, x1_sec, it_sec);
    printf("-------------------------------\n");

    // POSIÇÃO FALSA:
    printf("POSIÇÃO FALSA:\n\n");
    double a_fp = 0;
    double b_fp = 3.78;
    int it_fp = 11;

    false_position(f, a_fp, b_fp, it_fp);
    printf("-------------------------------\n");
    return 0;
}