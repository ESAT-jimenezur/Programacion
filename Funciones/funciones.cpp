#include <stdio.h>

float factorial(int n){
    /**
    *  Programa para calcular el factorial de
    *  un numero introducido por el usuario
    **/
    float resultado = 1;

    for(int i = 2; i < n; i++){

        resultado = resultado * i;

    }

    return resultado;
}

float potencia(int base, int exponente){
    /**
    *  Programa para calcular el resultado
    *  de multiplicar base por exponente
    **/

    float resultado = 1;

    if(exponente != 0){

        for(int i = 1; i <= exponente; i++){

            resultado *= base;

        }

    }

    return resultado;
}

bool compruebaNumeroEntreRangos(int n, int min, int max){
    int numero;
    if(n >= min && n <= max ){
        return true;
    }else{
        return false;
    }

    return false;
}

void tablasDeMultiplicar(){
    /**
    *  Programa que pregunta por un numero,
    *  el numero tiene que estar entre el 1 y el 10
    *  luego se muestran por pantalla todas las tablas de multiplicar
    *  desde ese numero hasta 10
    **/

    int numero;

    do{
        printf("Dime un numero entre 1 y 10 \n");
        scanf("%d", &numero);
    }while(!compruebaNumeroEntreRangos(numero, 1, 10));

    // El usuario ha introducido un numero correcto

    for(int i = numero; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");

    }

}





int main(){

    tablasDeMultiplicar();

}
