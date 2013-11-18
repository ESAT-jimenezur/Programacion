#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int random(){

    int nRandom;

    srand (time(NULL));

    nRandom = (rand()% 9999);

    return nRandom;
}

int logo(){
    printf("--------------------------------------\n");
    printf("------------- MASTER MIND ------------\n");
    printf("--------------------------------------\n");
}

int main() {

    bool debug = true;

    int numeroAzar = random();
    int nAzarCompleto = numeroAzar;
    int intentos = 10;
	int aciertos = 0;
	int posiciones = 0;
	bool ganaPersona = false;
	int numeroUsu;
	int numeroUsu0, numeroUsu1, numeroUsu2, numeroUsu3;


    // numeroAzar descompuesto.
	int numAzar0, numAzar1, numAzar2, numAzar3;
    int num0, num1, num2, num3;

    num0 = numeroAzar % 10;
    numeroAzar = numeroAzar / 10;

	num1 = numeroAzar  % 10;
	numeroAzar = numeroAzar / 10;

	num2 = numeroAzar  % 10;
	numeroAzar = numeroAzar / 10;

	num3 = numeroAzar  % 10;

    logo();


    do{
            printf("Introduce un numero\n");
            scanf("%d", &numeroUsu);

            numeroUsu0 = numeroUsu % 10;
            numeroUsu = numeroUsu / 10;

            numeroUsu1 = numeroUsu % 10;
            numeroUsu = numeroUsu / 10;

            numeroUsu2 = numeroUsu % 10;
            numeroUsu = numeroUsu / 10;

            numeroUsu3 = numeroUsu % 10;

            for(int i = 0; i <= 4; i++){
                if(num0 == numeroUsu0){
                    aciertos++;
                    if(i == 0)
                        posiciones++;
                }
                if(num1 == numeroUsu1){
                    aciertos++;
                    if(i == 1)
                        posiciones++;
                }
                if(num2 == numeroUsu2){
                    aciertos++;
                    if(i == 2)
                        posiciones++;
                }
                if(num3 == numeroUsu3){
                    aciertos++;
                    if(i == 3)
                        posiciones++;
                }

            }

            intentos--;

            if(aciertos >= 4 & posiciones >= 4){
                ganaPersona = true;
            }

            system("cls");

            logo();

            if(debug){
                printf("* DEBUG MODE ON *\n");
                printf("----- %d -----\n", nAzarCompleto);
                printf("* DEBUG MODE ON *\n\n");
            }
            printf("--------------------------------------\n");
            printf("Intentos: %d \n", intentos);
            printf("Aciertos: %d \n", aciertos);
            printf("Posiciones: %d \n", posiciones);
            printf("--------------------------------------\n");

            posiciones = 0;
            aciertos = 0;

    }while(intentos >= 0 && !ganaPersona);

    if(ganaPersona){
        system("cls");
        logo();
        printf("----------------------------------\n");
        printf("----- HAS GANADO LA PARTIDA! -----\n");
        printf("----------------------------------\n");
    }else{
        system("cls");
        logo();
        printf("--------------------------------------\n");
        printf("----- HAS PERDIDO LA PARTIDA! :( -----\n");
        printf("--------------------------------------\n");
    }

	return 0;
}
