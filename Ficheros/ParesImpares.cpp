#include <stdio.h>
#include <iJos.h>





int main(){

    seed();

    FILE *fichero_pares;
    FILE *fichero_impares;
    int cant_nums = 20;
    int numero = 0;
    int numero_leer = 0;

    fichero_pares = fopen("Ficheros/fichero_pares.dat", "wb");
    fichero_impares = fopen("Ficheros/fichero_impares.dat", "wb");

    for(int i = 0; i < cant_nums; i++){
        numero = aleatorio(100);
        if(numero%2 == 0){ //Pares
            fwrite(&numero, sizeof(int), 1, fichero_pares);
        }else{  //Impares
            fwrite(&numero, sizeof(int), 1, fichero_impares);
        }
    }

    fclose(fichero_pares);
    fclose(fichero_impares);

    printf("\n*********** PARES ***********\n");

    fopen("Ficheros/fichero_pares.dat", "rb");
    fopen("Ficheros/fichero_impares.dat", "rb");

    while(!feof(fichero_pares)){
        fread(&numero_leer, sizeof(int), 1, fichero_pares);
        if(!feof(fichero_impares)){
            printf("%d ", numero_leer);
        }
    }

    printf("\n*******************************\n");
    printf("\n*********** IMPARES ***********\n");

    while(!feof(fichero_impares)){
        fread(&numero_leer, sizeof(int), 1, fichero_impares);
        if(!feof(fichero_impares)){
            printf("%d ", numero_leer);
        }
    }
    printf("\n*******************************\n");

    fclose(fichero_pares);
    fclose(fichero_impares);

    return 0;
}
