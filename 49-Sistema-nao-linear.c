#include <stdio.h>

// Função 1
double g1(double x, double y){
    return x*x +  y*y - 5;
}

// Função 2
double g2(double x, double y){
    return x*x + x*y*y*y - 3;
}

// Derivada parcial em relação a x de g1
double g1x(double x, double y){
    return 2*x;
}

// Derivada parcial em relação a y de g1
double g1y(double x, double y){
    return 2*y;
}

// Derivada parcial em relação a x de g2
double g2x(double x, double y){
    return 2*x + y*y*y;
}

// Derivada parcial em relação a y de g2
double g2y(double x, double y){
    return 3*x*y*y;
}

double det(double x, double y) {
    // retorna o determinante de
    // [g1x,g1y]
    // [g2x, g2y]
    return g1x(x,y) * g2y(x,y) - g1y(x,y) * g2x(x,y);
}

void newton(double x, double y, int n) {
    for (int k = 0; k < n; k++) {
        double d = det(x,y);
        if (d == 0) {
            printf("Não é possível continuar.\n");
            return;
        }

        double xk = x - (g2y(x,y) * g1(x,y) - g1y(x,y) * g2(x,y)) / d;
        double yk = y - (-g2x(x,y) * g1(x,y) + g1x(x,y) * g2(x,y)) / d;

        printf("x^(%d) = %.16f\n", k + 1, xk);
        printf("y^(%d) = %.16f\n\n", k + 1, yk);
        x = xk;
        y = yk;
    }
}


int main() {
    // exemplo
    double x0 = -0.8977;
    double y0 = -2.0871;
    int n = 5;

    newton(x0, y0, n);
    return 0;
}
