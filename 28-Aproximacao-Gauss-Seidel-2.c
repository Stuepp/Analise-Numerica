//seidel corrigido
#include <stdio.h>
#include <math.h>
#define ROWS 4
#define COLS 4

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
            printf("%.16f\t", chute[k]);
        }
        printf("\n");

    }
}

int main(void){

    double a[ROWS][COLS] = {{10.74, -0.59, 4.77, 3.86},
                            {-0.47, -3.38, -0.15, 1.23},
                            {-3.33, -1.6, -8.24, 1.8},
                            {3.54, 4.64, 0.96, -10.66}};
    double b[ROWS] = {3.51, 3.06, 2.83, -1.48};

    double chute[COLS] = {-3.84,0.91,0.56,3.73};

    int n = 18;

    seidel(a,b,chute,n);

    return 0;
}
