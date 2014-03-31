#include <stdio.h>
#include <string.h>


FILE *f_texto1;
FILE *f_texto2;

const int max=50;

struct Pila{
    char cadena[max][80];
    int top;
};

Pila pila;

int main(){

    f_texto1 = fopen("texto1.txt", "r");
    f_texto2 = fopen("texto2.txt", "w");



    while(!feof(f_texto1)){
        /*
        char c = fgetc(f_texto1);
        if(!feof(f_texto1)){
            fputc(c-43, f_texto2);
        }
        */
        for(int i = 0; i < pila.top - 1; i++){
            char c = fgetc(f_texto1);
            pila.cadena[pila.top][i] = c;
            pila.top++;
        }


        //fputs(pila.cadena, f_texto2);
    }


    fputs(pila.cadena[pila.top], stdout);



    fclose(f_texto1);
    fclose(f_texto2);

    return 0;
}
