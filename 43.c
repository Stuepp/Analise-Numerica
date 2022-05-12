#include <stdio.h>
#include <math.h>
#define ROWS 6
#define COLS 6

void seidel(double a[ROWS][COLS], double b[COLS], double chute[COLS], int n);


int main() {
    double alpha = 30 * M_PI/180, beta = 60 * M_PI/180, f = -1000;

    // Seidel input
    double a[ROWS][COLS] = {{cos(alpha), 0, -cos(beta), 0, 0, 0},
                            {sin(alpha), 0, sin(beta), 0, 0, 0},
                            {-cos(alpha), -1, 0, -1, 0, 0},
                            {-sin(alpha), 0, 0, 0, -1, 0},
                            {0, 1, cos(beta), 0, 0, 0},
                            {0, 0, -sin(beta), 0, 0, -1}
    };

    double b[ROWS] = {0, f, 0, 0, 0, 0};

    double chute[COLS] = {1, 2, 3, 4, 5, 6};

    int n = 1;

    seidel(a,b,chute,n);

    return 0;
}

void seidel(double a[ROWS][COLS], double b[COLS], double chute[COLS], int n){
    for(int it = 0; it < n; it++){
        for(int i=0; i<ROWS; i++){
            double xi = b[i];
            for(int j = 0; j<COLS; j++){
                if(i!=j){
                    xi -= a[i][j] * chute[j];
                }
            }
            xi /= a[i][i];
            chute[i] = xi;
        }
        printf("X^(%d) ->", it +1);
        for(int k=0;k<COLS; k++){
            printf("%.8f\t", chute[k]);
        }
        printf("\n");

    }
}
