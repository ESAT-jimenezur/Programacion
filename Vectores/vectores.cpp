#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iJos.h>





int vector100enteros(){
    /**
    *  Crear un array unidimensional de 100 enteros,
    *  que lo cargue de 100 a 1 y lo muestre por pantalla
    **/

    int array[100];

    for(int i = 0; i < 100; i++){
        array[i] = 100 - i;
        //printf("%d \n", array[i]);
    }

    for(int i = 0; i < 100; i++){
        printf("%d \n", 100 - array[i]);

    }

}

void muestreo1000numeros(){

    /**
    * Programa que muestre por pantalla el resultado
    * de un muestreo de 1000 numeros aleatorios
    * comprendidos entre el 1 el 100
    **/

    int array[100];
    int n = 0;

    seed();

    for(int i = 0; i < 100; i++){
        array[i] = 0;
    }

    for(int i = 0; i < 999; i++){
        n = aleatorio(99);
        array[n] += 1;
    }

    for(int i = 0; i < 99; i++){
        if(array[i] != 0){
            printf("%d      --> %d  veces\n", i, array[i]);
        }
    }
}



void matrizDiagonal(){

    /**
    * Programa que muestre por pantalla el valor
    * de los valores de la diagonal
    **/

    int array[10][10];


    for(int i = 0; i < 10; i++{
        printf("%d", array[i][i]);
    }


}


int main(){

    matrizDiagonal();

}
