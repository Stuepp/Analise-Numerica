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

    double a[ROWS][COLS] = {{4, 1, -1},
                            {-1, 3, 1},
                            {1, -1, 5}};
    double b[ROWS] = {5, 6, 4};

    double chute[COLS] = {-1, -1, -1};

    int n = 10;

    seidel(a,b,chute,n);

    return 0;
}
