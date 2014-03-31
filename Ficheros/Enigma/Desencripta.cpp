#include <stdio.h>

FILE *f_encriptado;
FILE *f_desencriptado;


int main(){

    f_encriptado = fopen("encriptado.txt", "r");
    f_desencriptado = fopen("desencriptado.txt", "w");

    printf("Desencriptando...\n");

    while(!feof(f_encriptado)){
        char c = fgetc(f_encriptado);
        if(!feof(f_encriptado)){
            fputc(c-43, f_desencriptado);
        }
    }

    fclose(f_encriptado);
    fclose(f_desencriptado);

    return 0;
}

