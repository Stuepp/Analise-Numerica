#include <stdio.h>
#include <math.h>

// Defina a função matemática aqui:
double f(double x) {
    double  g = 9.81,
            v = 10.24,
            t = 5.76,
            l = 3.78,
            raiz = sqrt(2*g*x),
            tangente = tanh((raiz*t) / (2*l));

    return (raiz * tangente) - v;
}

// Defina sua derivada
double derivadaf(double x) {
    double  g = 9.81,
            t = 5.76,
            l = 3.78,
            raiz2l = sqrt(2) * l,
            gx = sqrt(g*x),
            tanhip = tanh((t * gx)/raiz2l),
            somatan = (sqrt(2) * tanhip)/gx,
            sech = 1/cosh((t * gx)/raiz2l),
            somasec = (t * sech * sech)/l;

    return 0.5 * g * (somatan + somasec);

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
    double a_bi = 0.25;
    double b_bi = 15.51;
    // numero de iterações:
    int it_bi = 12;

    bisection(f, a_bi, b_bi, it_bi);
    printf("-------------------------------\n");

    //NEWTON
    printf("NEWTON:\n\n");
    double x0_new = 1.32;
    int it_new = 5;

    newton (f, derivadaf, x0_new, it_new);
    printf("-------------------------------\n");

    // POSIÇÃO FALSA:
    printf("POSIÇÃO FALSA:\n\n");
    double a_fp = 0.24;
    double b_fp = 18.74;
    int it_fp = 11;

    false_position(f, a_fp, b_fp, it_fp);
    printf("-------------------------------\n");
    return 0;
}

