#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


int operacionesDosNumeros(){

    /*
     *  Programa que pide dos numeros y una operacion,
     *  Luego realiza la operacion y muestra el resultado por pantalla
     *
     */

    int num1, num2;
    char operacion;

    printf("Introduce un numero\n");
    scanf("%d", &num1);


    printf("Introduce otro numero\n");
    scanf("%d", &num2);

    printf("¿Que operacion quieres realizar? ( + - / * )");

    //Limpiamos buffer del teclado
    fflush(stdin);
    scanf("%c", &operacion);

    //Comprobamos que introduzca un valor bueno
    if(operacion == '+' || operacion == '-' || operacion == '/' || operacion == '*'){

        //SUMA
        if(operacion == '+'){
            printf("El resultado de %d + %d es %d", num1, num2, num1+num2);
        }

        //RESTA
        if(operacion == '-'){
            printf("El resultado de %d - %d es %d", num1, num2, num1-num2);
        }

        //DIVISION
        if(operacion == '/' && num2 == 0){
            printf("El resultado de %d / %d es %d", num1, num2, num1/num2);
        }

        //MULTIPLICACION
        if(operacion == '*'){
            printf("El resultado de %d * %d es %d", num1, num2, num1*num2);
        }

    }else{
        printf("Esa operacion no esta soportada");
    }

}

int operacionesDosNumerosV2(){

    /*
     *  Programa que pide dos numeros y una operacion,
     *  Luego realiza la operacion y muestra el resultado por pantalla
     *
     */

    int num1, num2;
    char operacion;

    printf("Introduce un numero\n");
    scanf("%d", &num1);


    printf("Introduce otro numero\n");
    scanf("%d", &num2);

    printf("¿Que operacion quieres realizar? ( + - / * )");

    //Limpiamos buffer del teclado
    fflush(stdin);
    scanf("%c", &operacion);

    switch(operacion){
        case '+':
            printf("El resultado de %d + %d es %d", num1, num2, num1+num2);
            break;
        case '-':
            printf("El resultado de %d - %d es %d", num1, num2, num1-num2);
            break;
        case '/':
            if(num2 == 0){
                printf("El segundo numero no puede ser 0");
            }else{
                printf("El resultado de %d / %d es %d", num1, num2, num1/num2);
            }
            break;
        case '*':
            printf("El resultado de %d * %d es %d", num1, num2, num1*num2);
            break;
        default:
            printf("Esa operacion no esta soportada");
    }

}

int mayorTresNumeros(){

    /*
     *  Programa que pide por pantalla 3 numeros y calcula cual es el mayor
     */

    int num1, num2, num3;



}

int sucesion1(){
    /**
      * Introducir un numero por pantalla y usarlo como limite en una sucesion desde 0 hasta ese numero
    **/

      int limite;

      printf("Dime un limite");
      scanf("%d", &limite);

    for(int i = 1; i <= limite; i++){
        if(i % 10 == 0){
            printf("\n");
        }else{
            printf("%05d ", i);
        }
    }

}

int juego15Objetos(){

    int objetos = 15;
    int jugador, maquina;

    printf("Turno ORDENADOR, quita 2 \n");
    objetos = objetos - 2;

    printf("Quedan %d objetos\n", objetos);

    do{

        printf("Turno JUGADOR; Quita (1, 2 o 3 objetos) \n");
        scanf("%d", &jugador);
        while(jugador < 1 || jugador > 3){
            printf("No puedes introducir ese numero. Introduce 1, 2 o 3 \n");
            scanf("%d", &jugador);
        }

        objetos = objetos - jugador;

        printf("Has quitado %d objetos, quedan %d objetos\n", jugador, objetos);

        maquina = 4 - jugador;
        objetos = objetos - maquina;

        printf("Turno ORDENADOR, quita %d objetos, quedan %d objetos\n", maquina, objetos);

        if(objetos <= 1){
            printf("GAME OVER");
        }

    }while(objetos > 1);

}

int calcularFactorial(){

    float resultado = 1, numero;
}

int calcularBaseExponente(){
    int base, exponente, resultado, i;


    printf("Dame una base\n");
    scanf("%d", &base);

    printf("Dame unexponente\n");
    scanf("%d", &exponente);

    if(exponente != 0){
        for(i = 1; i <= exponente; i++){
            resultado *= base;
        }
    }
    printf("El resultado de %d elevado a %d es %d\n", base, exponente, resultado);

}

int serieNumeros(){

/**
  * Implementar un programa en C que pida al usuario un numero
  * Y muestre por pantalla la serie desde 1 hasta ese numero
  *
  **/

    int numero, i, j;

    printf("Dime un numero\n");
    scanf("%d", &numero);

    printf("LIMITE: %d \n", numero);

    for(i = 1; i <= numero; i++){
        if(i % 10 == 0){
            printf("%05d \n", i);
        }else{
            printf("%05d ", i);
        }
    }


}

int flechaNumeros(){

/**
  * Al usuario se le pide un tope, y se muestra una flecha
  **/


    int numero, i, j;

    printf("Dime un numero\n");
    scanf("%d", &numero);
    printf("\n");

    for(i = 1; i <= numero; i++){
        for(j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(i = numero-1; i >= 1; i--){
        for(j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

}

int rombo(){

    /**
      *
      * Hacer un rombo indicando
      *
      **/

    int altura = 20;
    int i, j, h;

    printf("Dime una altura\n");
    scanf("%d", &altura);
    system("cls");

    for(i = 0; i <= altura; i++){
        for(j = 0; j <= altura - i; j++){
            printf(" ");
        }
        for(j = 1; j <= (i*2)-1; j++){
            printf("*");
        }
        printf("\n");
    }

    for(i = altura - 1 ; i >= 1; i--){
        for(j = 0; j <= altura - i; j++){
            printf(" ");
        }
        for(j = 0; j <= (i*2)-2 ; j++){
            printf("*");
        }
        printf("\n");
    }
}


int main(){



}
