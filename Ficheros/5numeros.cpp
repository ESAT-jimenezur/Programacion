#include <stdio.h>

/** Implementar un programa en C que
    pregunte al usuario 5 numeros enteros
    y que los almacene en un fichero que se
    llamara numeros.dat
    Una vez realizado, abrirá el fichero en modo
    lectura y los mostrara por pantalla

    fread(<variable>,<tamaño de bloque>,<nº bloques>,<fichero>);
    fwrite(<variable>,<tamaño de bloque>,<nº bloques>,<fichero>);
*/



int main(){

    FILE *fichero;
    int i = 0;
    int lectura = 0;
    int n = 0;


    fichero = fopen("Ficheros/5numeros.dat", "wb");

    while(i < 5){

        printf("Numero: ");

        scanf("%d", &n);

        fwrite(&n, sizeof(int), 1, fichero);

        i++;
    }

    printf("\n\n");

    fclose(fichero);

    fichero = fopen("Ficheros/5numeros.dat", "rb");

    for(int j = 0; j < 5; j++){
        fread(&lectura, sizeof(int), 1, fichero);
        printf("%d \n", lectura);
    }

    fclose(fichero);

    return 0;
}
