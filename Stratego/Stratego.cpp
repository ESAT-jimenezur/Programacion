#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

#include <iJos.h>

bool debug = true;


int cursorX = 0;
int cursorY = 0;

int posActualX = 0;
int posActualY = 0;

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

void pintaParrilla(){
    setColors(0, 14);
    parrilla(0, 0, 10, 10, 10, 6, 1, 1);

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

                posActualY --;
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

                posActualY ++;
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

                posActualX ++;
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

                posActualX --;
                cursorX -= 11;
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 13:
                pintaParrilla();
                setColors(0, 15);

                ventana(cursorX, cursorY, 10, 6, 0);
            break;
    }



}

void modoDebug(){

    if(debug){
        setColors(0, 15);
        cursorPos(115, 0);
        printf("Posicion %d - %d  \n", posActualX, posActualY);
    }
}

void juego(){


    ventanaConsola(155,73, "iJoStratego");
    pintaParrilla();

    // Marcamos la primera casilla
    setColors(0, 13);
    ventana(0, 0, 10, 6, 1);

    setColors(0,14);

    for(int j=110; j < 112; j++){
       for(int i=0; i < 70; i++){
           cursorPos(j,i);
           printf("%c",179);
       }
    }



    do{

        modoDebug();
        // Este metodo controla el movimiento del cursor
        movimientoCursor();





    }while(true);


}


int main(){

    //De momento llamamos al juego y no al menu.

    juego();
    //menu();

}

