//seidel corrigido
#include <stdio.h>
#include <math.h>
#define ROWS 3
#define COLS 3

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

    double a[ROWS][COLS] = {{-5.87, 0.68, -3.53},
                            {0.03, 6.25, -4.56},
                            {-0.58, -1.72, -3.96}};
    double b[ROWS] = {-1.28, 1.63, 4.2};

    double chute[COLS] = {-3.53,0.29,0.32};

    int n = 18;

    seidel(a,b,chute,n);

    return 0;
}
