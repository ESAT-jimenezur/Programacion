#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

#include <iJos.h>

using namespace std;

void setColors(int texto, int fondo){

    colorTexto(texto, fondo);

}


void juego(){

    bool partidaActiva = true;
    bool debug = true;
    int jugador = 2;
    int ordenador = 10;
    int turno = 0; // Turno 0 = ordenador, 1 = persona

    int tablero[4][4] = {       // Array  tablero (Ultima fila y columna solo son para debuguear)
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0
                        };

     int letrasTablero [4][4] = {       // Array  tablero (Ultima fila y columna solo son para debuguear)
                            7, 8, 9,
                            4, 5, 6,
                            1, 2, 3
                        };


    // Establecemos el color de la consola
    setColors(0, 14);

    do{


        if(turno == 0){ // Turno  == 0 -> Ordenador

            tablero[2][2] = ordenador;

        }else{ // Turno  == 1 -> Persona



        }





        //Recorremos array y mostramos
        for(int i = 1; i <= 3; i++){

            for(int j = 1; j <= 3; j++){
                printf(" %d  ", tablero[i][j]);
            }
            printf("\n");

        }



        if(debug){

            printf("\n\n\n");
            //Recorremos array y mostramos
            for(int i = 1; i <= 4; i++){

                for(int j = 1; j <= 4; j++){

                }
                printf("\n");

            }
        }


        printf("---------------\n");
        if(turno == 0){ // Turno  == 0 -> Ordenador
            printf("Turno del ordenador");
        }else{ // Turno  == 1 -> Persona
            printf("Turno del jugador");
        }



        partidaActiva = false;




    }while(partidaActiva);


}

int main(){

    juego();

}



