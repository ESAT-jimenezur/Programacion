#include <stdio.h>

FILE *f_original;
FILE *f_encriptado;


int main(){

    f_original = fopen("original.txt", "r");
    f_encriptado = fopen("encriptado.txt", "w");

    printf("Encriptando...\n");

    while(!feof(f_original)){
        char c = fgetc(f_original);
        if(!feof(f_encriptado)){
            fputc(c+43, f_encriptado);
        }
    }

    fclose(f_original);
    fclose(f_encriptado);

    return 0;
}

