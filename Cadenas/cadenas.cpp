#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include <iJos.h>

/***********************************************************
 ** gets(cadena) --> fgets(cadena, dimension, stdin)      **
 ** puts(cadena) --> fputs(cadena, stdout)                **
 **                                                       **
 ** strcpy(c1, c2) Copia la cadena2 en la cadena1         **
 ** strcat(c1, c2) Concatena la cadena2 en la cadena1     **
 ** strlen(c1) Devuelve la longitud de la cadena1         **
 ** strcmp(c1, c2) Compara ambas cadenas, devuleve un     **
 **   /valor entero. (Si es menor a 0, c1 sera mayor a c2,**
 **   /si es mayor a 0, c2 sera mayor a c1,               **
 **   /si es 0, iguales.                                  **
 **                                                       **
 ** strupr(c1) Pasa c1 a mayusculas                       **
 ** strlwr(c1) Pasa c1 a minusculas                       **
***********************************************************/


/****************************************************************************************
 **   Implementar un programa en C que lea cadenas por teclado hasta que el usuario    **
 **   escriba la palabra "salir" y entonces se muestren por pantalla todas las cadenas **
 **   escritas al contrario.                                                           **
 ****************************************************************************************/
void ejercicio2(){

    bool ejecucion = true;

    char cadenas[20][80];
    char indice;



    char cadenaIntroducida[80];

    while(ejecucion){

        fgets(cadenaIntroducida, 80, stdin);

        cadenaIntroducida[strlen(cadenaIntroducida)-1] = '\0';

        strcpy(cadenas[indice], cadenaIntroducida);

        indice++;

        if( strcmp(strupr(cadenaIntroducida), "SALIR\0") == 0 ){
            ejecucion = false;
        }

    }


    for(int i = 0; i < indice - 1; i++){
        for(int j = strlen(cadenas[i])-1;  j >= 0; j--){
            printf("%c", cadenas[i][j]);
        }
        printf("\n");
    }


}

void ejercicio3(){





}

void fejercicio4(){



}



void ejercicio5(){

    bool ejecucion = true;

    char cadena[20] = "Esto es una cadena";
    char cadenas[20][4];
    char caracterActual;
    int j = 0;

    //fputs(cadena, stdout);

    for(int i = 0; i < strlen(cadena); i++){

        //printf("%c", cadena[i]);

        cadenas[j][i] = cadena[i];

        if(!cadena[i] == 32){
            j++;
        }

        if (i == strlen(cadena)){
            cadena[i] = '\n';
        }
    }








    /*

        for(int variableMolona = 0; variableMolona < 10; variableMolona++){
            for(int variableNoTanMolona = 0; variableNoTanMolona < 20; variableNoTanMolona++){
                if(cadenas[variableMolona][variableNoTanMolona] != 0){
                    printf("%c", cadenas[variableMolona][variableNoTanMolona]);
                }
            }
        }

        */

    /*
    for(int i = 0; i < indice - 1; i++){
        for(int j = strlen(cadenas[i])-1;  j >= 0; j--){
            printf("%c", cadenas[i][j]);
        }
        printf("\n");
    }
    */

}


int main(){

    ejercicio5();

    return 0;
}
