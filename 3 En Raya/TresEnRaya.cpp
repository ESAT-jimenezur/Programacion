#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

#include <iJos.h>

using namespace std;


    bool partidaActiva = true;
    bool debug = false;
    int jugador = 2;
    int ordenador = 10;
    int turno = -1; // Turno -1 = ordenador, 1 = persona
    int fichasOrdenador = 3;
    int fichasPersona = 3;
    int ale;


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



void setColors(int texto, int fondo){

    colorTexto(texto, fondo);

}

void pintaX(int posX, int posY){

    cursorPos(posX, posY);

    int x[5][5] = {
                        1,0,0,0,1,
                        0,1,0,1,0,
                        0,0,1,0,0,
                        0,1,0,1,0,
                        1,0,0,0,1
    };
    printf(" ");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(x[i][j] == 1){
                printf("%c", 254);
            }else{
                printf(" ");
            }
        }
        if(i == 0){
            posX++;
        }
        posY++;
        cursorPos(posX, posY);
    }
}

void ponerFicha(int casilla, int turno){
    int fichas;
    int posAux;
    if(fichasOrdenador > 0 && fichasPersona > 0){
        if(turno == -1){
            fichas = ordenador;
            fichasOrdenador--;
        }else{
            fichas = jugador;
            fichasPersona--;
        }

        if(casilla == 1 && tablero[1][1] == 0)tablero[1][1] = fichas;
        if(casilla == 2 && tablero[1][2] == 0)tablero[1][2] = fichas;
        if(casilla == 3 && tablero[1][3] == 0)tablero[1][3] = fichas;

        if(casilla == 4 && tablero[2][1] == 0)tablero[2][1] = fichas;
        if(casilla == 5 && tablero[2][2] == 0)tablero[2][2] = fichas;
        if(casilla == 6 && tablero[2][3] == 0)tablero[2][3] = fichas;

        if(casilla == 7 && tablero[3][1] == 0)tablero[3][1] = fichas;
        if(casilla == 8 && tablero[3][2] == 0)tablero[3][2] = fichas;
        if(casilla == 9 && tablero[3][3] == 0)tablero[3][3] = fichas;

    }else{ // Retirar ficha
        printf("Elige una ficha para mover.\n");
    }

}

void pideFicha(int turno){
    int casilla;
    //Escaneamos el valor introducdo por teclado
    scanf("%d", &casilla);
    if (casilla > 1 || casilla < 9){
        ponerFicha(casilla, turno);
    };
}

void compruebaTurno(int turno){
    cursorPos(1, 21);
    if(turno == -1){ // Turno  == -1 -> Ordenador
        printf("Turno del ORDENADOR. Introduce una casilla\n");
    }else{ // Turno  == 1 -> Persona
        printf("Turno del JUGADOR. Introduce una casilla\n");
    }
}

void imprimeTablero(){
    //Recorremos array y mostramos
    /*
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            printf(" %.2d  ", tablero[i][j]);
        }
        printf("\n");
    }*/
    parrilla(0, 0, 3, 3, 10, 6, 1, 1);

    pintaX(1, 1);

    printf("\n");
}

void imprimeTableroDebug(){
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
}


void compruebaJugada(){

    int fila_1 = tablero[1][1] + tablero[1][2] + tablero[1][3];
    int fila_2 = tablero[2][1] + tablero[2][2] + tablero[2][3];
    int fila_3 = tablero[3][1] + tablero[3][2] + tablero[3][3];

    if(fila_1 == 30 || fila_1 == 6 || fila_2 == 30 || fila_2 == 6 || fila_3 == 30 || fila_3 == 6){
        partidaActiva = false;
    }

    // TODO

}

void juego(){


    // Establecemos el color de la consola
    setColors(0, 14);

    do{
        printf("%d\n\n", turno);
       //resets();

        //Muestra / Actualiza el tablero en pantalla
        imprimeTablero();

        //Solo si el modo debug está activo
        imprimeTableroDebug();


        compruebaTurno(turno);
        pideFicha(turno);


        //Ajustamos turno
        turno = turno * (-1);

        compruebaJugada();


        system("cls");

    }while(partidaActiva);


}

int main(){
    juego();
}



