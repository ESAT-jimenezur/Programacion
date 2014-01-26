#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

#include <iJos.h>



/**********************************
** Declaraciones de librerias    **
** con funcionalidades del juego **
**********************************/

#include <Utils.h>
#include <Jugadas.h>



/***********************
** Variables Globales **
************************/

bool debug = true;
bool seEstaJugando = true;
int posInicialCursorX = 0;

int posInicialCursorY = 42;

int cursorX = posInicialCursorX;
int cursorY = posInicialCursorY;

int posActualX = 0;
int posActualY = 0;

int fichaSeleccionada = false;

int tablero[10][10] = {
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};


int arrayTemporalJugada[10][4];

void juego();


void menu(){

    printf("***** Seleccionar Jugada *****\n");
    printf("1.- Defensiva\n");
    printf("2.- Agresiva\n");
    printf("3.- Colocar las fichas\n");

    int c;
    scanf("%d", &c);

    switch (c){
        case 1:

            break;
        case 2:

            break;
        case 3:
            juego();
            break;
    }

}

void setColors(int texto, int fondo){
    colorTexto(texto, fondo);
}

void setFichas(int tipoJugada){

    // Primero vamos a rellenar la parte superior del tablero con las fichas aleatorias del pc
    // Esto genera las fichas del PC Aleatorias
    /* TODO */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            tablero[i][j] = aleatorio(10) + 100;
        }
    }

    // Comprobamos el tipo de jugada, para asignar fichas
    //Hora generamos las del jugador

    switch (tipoJugada){
        case 0: // Fichas Aleatorias
            for(int i = 6; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    tablero[i][j] = aleatorio(10);
                }
            }
        break;
        case 1: //Jugada defensiva
            // Nos 'traemos' el array de la jugada a uno temporal
            asignaArray(arrayTemporalJugada, j_Defensiva);
            setColors(0, 15);
            cursorPos(115, 1);
            printf("Estrategia Defensiva");
            for(int i = 6; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    tablero[i][j] = arrayTemporalJugada[i-6][j];
                }
            }
        break;
    }




    // Ahora vamos a dar el valor a las casillas inalcanzables
    // El numero 999 es el que vamos a usar
    //Fila1
    tablero[4][2] = 999;
    tablero[4][3] = 999;
    tablero[4][6] = 999;
    tablero[4][7] = 999;
    //Fila2
    tablero[5][2] = 999;
    tablero[5][3] = 999;
    tablero[5][6] = 999;
    tablero[5][7] = 999;
}



void pintaCasillasInaccesibles(){
    setColors(0, 3);
    //Pintamos primera casilla a la que no accedemos
    ventana(22, 28, 10, 6, 0);
    //2a casilla
    ventana(33, 28, 10, 6, 0);
    //Debajo de ambas
    ventana(22, 35, 10, 6, 0);
    ventana(33, 35, 10, 6, 0);

    //Pintamos las otras 4 casillas de la derecha
    //Arriba
    ventana(66, 28, 10, 6, 0);
    ventana(77, 28, 10, 6, 0);
    //Abajo
    ventana(66, 35, 10, 6, 0);
    ventana(77, 35, 10, 6, 0);


}

void pintaParrilla(){

    int xIni = 0;
    int yIni = 0;


    int x = 0;
    int y = 42;

    setColors(0, 14);
    parrilla(0, 0, 10, 10, 10, 6, 1, 1);

    pintaCasillasInaccesibles();

    //Reset de posicion
    cursorPos(x+4, y+3);
    setColors(0, 15);

    // Pinta por pantalla las fichas del jugador
    for(int i = 6; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", tablero[i][j]);
            x += 11;
            cursorPos(x+4, y+3);
        }
        x = 0;
        y += 7;
        cursorPos(x+4, y+3);
    }

    //Reset de posicion
    cursorPos(xIni+4, yIni+3);



    //Pintamos por pantalla las fichas del PC
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", tablero[i][j]);
            xIni += 11;
            cursorPos(xIni+4, yIni+3);
        }
        xIni = 0;
        yIni += 7;
        cursorPos(xIni+4, yIni+3);
    }
}

void pintaNombreFicha(int id_Ficha){
    cursorPos(115, 5);

    // Limpio de forma cutrilla la linea, para que no se solapen los nombres
    printf("                     ");
    switch (id_Ficha){
        case 1:
            printf("Mariscal");
            break;
        case 2:
            printf("General");
            break;
        case 3:
            printf("Coronel");
            break;
        case 4:
            printf("Comandante");
            break;
        case 5:
            printf("Capitan");
            break;
        case 6:
            printf("Teniente");
            break;
        case 7:
            printf("Sargento");
            break;
        case 8:
            printf("Minero");
            break;
        case 9:
            printf("Explorador");
            break;
        case 10:
            printf("Espia");
            break;
        case 99:
            printf("Bomba");
            break;
        case 100:
            printf("Bandera");
            break;
    }


}

void movimientoCursor(){

    //Vaciamos el buffer;
    fflush(stdin);

    char c;
    c = getch();

    if(c == 32){
        c = getch();
    }



    switch (c){
        /**
            REVISAR QUE NO SE SALGA DE PANTALLA
        **/

        case 72:
            // Arriba
            if(cursorY > 0){
                //Repintamos la parrilla
                pintaParrilla();
                setColors(0, 13);

                posActualX --;
                cursorY -= 7;
                ventana(cursorX, cursorY, 10, 6, 0);
            }else{
                setColors(0, 15);
                cursorPos(115, 0);
                printf("Esa posicion no es valida");
            }
            break;
        case 80:
            // Abajo
            if(cursorY < 57){
                //Repintamos la parrilla
                pintaParrilla();
                setColors(0, 13);

                posActualX ++;
                cursorY += 7;
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 77:
            // Derecha
            if(cursorX < 92){
                //Repintamos la parrilla
                pintaParrilla();
                setColors(0, 13);

                posActualY ++;
                cursorX += 11;
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 75:
            // Izquierda
            if(cursorX > 0){
                //Repintamos la parrilla
                pintaParrilla();
                setColors(0, 13);

                posActualY --;
                cursorX -= 11;
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 13: // Pulsamos ENTER
                pintaParrilla();
                //Ponemos color blanco
                setColors(0, 15);
                //Repintamos el cuadrado actual en el color de arriba
                ventana(cursorX, cursorY, 10, 6, 0);



                cursorPos(115, 5);
                //fichaSeleccionada = fichasJugador[posActualX][posActualY];



                //printf("%d", fichasJugador[posActualX][posActualY]);

            break;
    }



}



/**************************************
 ** Este metodo es utilizado por las **
 ** fichas para atacar a otras       **
 **                                  **
 ** @get                             **
 ** int atacante (El tipo de ficha)  **
 ** int receptor (El tipo de ficha)  **
 ** @return                          **
 ** int ganador (La ficha que gana)  **
**************************************/

int atacar(int atacante, int receptor){
    bool ganador;

    //Definimos los tipos de batalla, para saber quien gana.

    /** TODO
        - Comprobar que los valores sean correctos
        - Comprobar el caso de partida ganada
    **/

    if(atacante == 1 && receptor == 12){ // En este caso, el atacante, usando el espia ha atacado al mariscal.
        ganador = 1; // Gana el atacante
    }


    if(receptor == 100){ // Si el atacante toca la bandera
        ganador = 1;
        //TODO
        //partidaGanada = true;
    }

    if(receptor == 99){ // 99 Es la bomba
        if(atacante == 3){ // Tenemos un minero desactivador de bombas!
            ganador = 1; // Bomba desactivada!
        }else{
            ganador = 0; // Te has chocado con la bomba, amigo!
        }
    }

    return ganador;
}



void modoDebug(){
    if(debug){
        //Color Rojo-Debug
        setColors(0, 12);
        //Dibujamos ventana de debug
        ventana(112, 40, 42, 30, 0);

        cursorPos(122, 40);
        printf("|******|DEBUG/\\ZONE|******|");

        // Debug del cursor
        cursorPos(113, 42);
        printf("Posicion del puntero %d - %d  \n", posActualX, posActualY);


        /* Pequeño debug de array */
        cursorPos(113, 44);
        printf("|**-**-**|Debug del Tablero|**-**-**|");
        int y = 46;
        for(int i = 0; i < 10; i++){
            cursorPos(113, y++);
            for(int j = 0; j < 10; j++){
                printf("%.3d ", tablero[i][j]);
            }
            printf("\n");
        }

    }
}

void logs(){

    //Color Rojo-Debug
    setColors(0, 13);
    //Dibujamos ventana de debug
    ventana(112, 34, 42, 5, 0);
    cursorPos(125, 34);
    printf(" Eventos ");


}


void juego(){
    ventanaConsola(155,73, "iJoStratego");

    //Iniciamos la jugada defensiva
    setFichas(1);

    pintaParrilla();

    // Marcamos la primera casilla
    setColors(0, 13);

    //Posicion Inicial
    ventana(posInicialCursorX, posInicialCursorY, 10, 6, 1);

    // Esto pinta las dos lineas a la derecha del tablero, que lo separan del "HUD"
    setColors(0,14);
    for(int j=110; j < 112; j++){
       for(int i=0; i < 70; i++){
           cursorPos(j,i);
           printf("%c",179);
       }
    }



    do{

        modoDebug();
        logs();
        // Este metodo controla el movimiento del cursor
        //pintaNombreFicha(fichasJugador[posActualX][posActualY]);
        movimientoCursor();





    }while(seEstaJugando);


}


int main(){

    //De momento llamamos al juego y no al menu.

    juego();
    //menu();

}

