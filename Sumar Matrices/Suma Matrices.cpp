#include <stdio.h>
#include <conio.h>
#include <iJos.h>

const int x = 10;
const int y = 10;

void llenarMatriz(int matriz[x][y]){
    int nAle = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            nAle = aleatorio(100);
            matriz[i][j] = nAle;
        }
    }
}

void imprimirMatriz(int matriz[x][y]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%.3d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
}

void sumarMatrices(int matriz_A[x][y], int matriz_B[x][y], int suma[x][y]){

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            suma[i][j] =  matriz_A[i][j] + matriz_B[i][j];
        }
    }
}

int main(){

    seed();

    int matriz_A[x][y];
    int matriz_B[x][y];
    int suma[x][y];

    llenarMatriz(matriz_A);
    imprimirMatriz(matriz_A);

    llenarMatriz(matriz_B);
    imprimirMatriz(matriz_B);

    sumarMatrices(matriz_A, matriz_B, suma);

    imprimirMatriz(suma);


}
