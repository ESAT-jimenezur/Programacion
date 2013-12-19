#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

#include <iJos.h>


int cursorX = 0;
int cursorY = 0;


void setColors(int texto, int fondo){
    colorTexto(texto, fondo);
}

void pintaParrilla(){
    setColors(0, 14);
    parrilla(0, 0, 10, 10, 10, 6, 1, 1);
}

void cursorSelector(){

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

                cursorX -= 11;
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
    }



}



void juego(){

    while(true){





        cursorSelector();


    }


}


int main(){
    // Pantalla default
    ventanaConsola(155,73, "Stratego");
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

    juego();
}

