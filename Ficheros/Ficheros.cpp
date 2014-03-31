#include <stdio.h>


/**
    fgets(cadena, 80, fichero);
    fputs(cadena, fichero);
    fgetc(fichero); //Devuelve un caracter
    fputc(caracter, fichero); //Poner un caracter
    while(!feof(fichero)); //Lee el fichero hasta que este se acabe

        ----------- BINARIOS -----------
    fread(<variable>,<tamaño de bloque>,<nº bloques>,<fichero>);
    fwrite(<variable>,<tamaño de bloque>,<nº bloques>,<fichero>);

    fseek(<fichero>, <salto bloques>, <origen>;
    seek_set(principio)
    seek_cur(posicion actual)
    seek_end(final del fichero)

**/


FILE *fichero;


int main(){


    //fichero = fopen("fichero.txt", "r");

    fichero = fopen("Ficheros/otro.txt", "r");

    //fputs("Ejemplo de cadena.", fichero);

    /*
    c = fgetc(fichero);
    fputc(c, fichero);
    */

    while(!feof(fichero)){
        char c = fgetc(fichero);
        printf("%c", c);
    }

    fclose(fichero);


    return 0;
}
