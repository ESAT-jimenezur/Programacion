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

void ponerFicha(int turno){
    int posicion;
    if(turno == -1){// Turno PC
        printf("Turno del ORDENADOR \n");
        scanf("%d", &posicion);
         while (posicion < 1|| posicion > 9){

         };
         posicion--;
         printf("_______________________________\n");
         //AjustaTurno(casilla);
    }else{

    }

}

void juego(){

    bool partidaActiva = true;
    bool debug = true;
    int jugador = 2;
    int ordenador = 10;
    int turno = -1; // Turno 0 = ordenador, 1 = persona
    int fichasOrdenador = 3;
    int fichasPersona = 3;

    int tablero[4][4] = {       // Array  tablero (Ultima fila y columna solo son para debuguear)
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0
                        };

    // Se le llamó "letras Tablero" pero la idea después fue utilizar el teclado numérico para jugar
    int letrasTablero [4][4] = {       // Array  tablero (Ultima fila y columna solo son para debuguear)
                            7, 8, 9,
                            4, 5, 6,
                            1, 2, 3
                        };
    int ale;

    // Establecemos el color de la consola
    setColors(0, 14);

    do{



        //Recorremos array y mostramos
        for(int i = 1; i <= 3; i++){

            for(int j = 1; j <= 3; j++){
                printf(" %d  ", tablero[i][j]);
            }
            printf("\n");

        }


        // Muestra el debug (Si está activo)
        if(debug){

            printf("\n\n\n");
            //Recorremos array y mostramos
            for(int i = 1; i <= 4; i++){

                for(int j = 1; j <= 4; j++){

                }
                printf("\n");

            }
        }

        ponerFicha(turno);


        printf("---------------\n");
        if(turno == 0){ // Turno  == 0 -> Ordenador
            printf("Turno del ordenador");
        }else{ // Turno  == 1 -> Persona
            printf("Turno del jugador");
        }


        //                 COMBPROBAMOS SUMA HORIZONTAL         ||          COMPROBAMOS SUMA VERTICAL                  ||           COMPROBAMOS SUMA VERTICAL
        if( tablero[0][0] + tablero[0][1] + tablero[0][2] == 30 || tablero[0][0] + tablero[1][0] + tablero[2][0] == 30 || tablero[0][0] + tablero[1][1] + tablero[2][2] == 30){
            printf("Gana ordenador");
            partidaActiva = false;
        }else{
            printf("Gana persona");
            partidaActiva = false;
        }


    }while(partidaActiva);


}

int main(){

    //juego();

}



