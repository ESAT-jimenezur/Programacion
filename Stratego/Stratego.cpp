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

int posFichaSeleccionadaX = 0;
int posFichaSeleccionadaY = 0;

int cursorPosAnteriorX = 0;
int cursorPosAnteriorY = 0;

int fichasMovidas1aFilaPC = 0;

int fichaSeleccionada = 0;
bool hayFichaSeleccionada;
int turno = 1; //Turno 1 = Persona, -1 = PC

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

int arrayTemporalJugada[4][10] = {
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};



void juego(int tipoInicio);
void logs(int log);
void logFichas();
void movimientoPC();
void compruebaCombate(int turno, int valorAtacante, int posX_Inicio, int PosY_Inicio, int PosX_Destino, int posY_Destino);

void menu(){

    printf("***** Seleccionar Jugada *****\n");
    printf("1.- Defensiva\n");
    printf("2.- Agresiva\n");
    printf("3.- Colocar las fichas\n");

    int c;
    scanf("%d", &c);

    switch (c){
        case 1:
            juego(1); //Jugada Defensiva
            break;
        case 2:
            juego(2); //Jugada Agresiva
            break;
        case 3:
            juego(3); //Colocar Fichas
            break;
    }

}

void setColors(int texto, int fondo){
    colorTexto(texto, fondo);
}

void setFichas(int tipoJugada){

    seed(); //Iniciamos una nueva "Semilla" para que nos salgan aleatorios

    // Primero vamos a rellenar la parte superior del tablero con las fichas aleatorias del pc
    // Esto genera las fichas del PC Aleatorias
    /* TODO */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            tablero[i][j] = aleatorio(12) + 100;
        }
    }

    // Comprobamos el tipo de jugada, para asignar fichas
    //Hora generamos las del jugador

    switch (tipoJugada){
        case 1: //Jugada defensiva
            // Nos 'traemos' el array de la jugada a uno temporal
            //asignaArray(arrayTemporalJugada, j_Defensiva);
            setColors(0, 15);
            cursorPos(115, 1);
            printf("Estrategia Defensiva");

            for(int i = 6; i < 10; i++){
                //cursorPos(115, i++);
                for(int j = 0; j < 10; j++){
                    tablero[i][j] = j_Defensiva[i - 6][j];
                }
            }
        break;
        case 2: //Jugada Agresiva
            // Nos 'traemos' el array de la jugada a uno temporal
            asignaArray(arrayTemporalJugada, j_Agresiva);
            setColors(0, 15);
            cursorPos(115, 1);
            printf("Estrategia Agresiva");
            for(int i = 6; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    tablero[i][j] = arrayTemporalJugada[i - 6][j];
                }
            }
        break;
        case 3:





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
    int y = 0;

    setColors(0, 14);
    parrilla(0, 0, 10, 10, 10, 6, 1, 1);

    pintaCasillasInaccesibles();

    //Reset de posicion
    cursorPos(x+4, y+3);
    setColors(0, 15);

    //Nuevo metodo de pintado
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){

            if(debug){
                //Si tenemos el modo debug habilitado, pintamos todo menos las casillas vacias y el agua
                if(tablero[i][j] == 0){
                      printf("   ");
                }else if(tablero[i][j] == 999){
                    printf(" ");
                }else{
                    printf("%d ", tablero[i][j]);
                }
            }else{
                //Sino, pintamos solo lo del jugador
                if(tablero[i][j] >= 100 && tablero[i][j] < 999){
                    printf("?");
                }else if(tablero[i][j] == 0 || tablero[i][j] == 999){
                    printf(" ");
                }else{
                    printf("%d ", tablero[i][j]);
                }

            }
            xIni += 11;
            cursorPos(xIni+4, yIni+3);
        }
        xIni = 0;
        yIni += 7;
        cursorPos(xIni+4, yIni+3);
    }

    //Volvemos a poner el color "Azul" de casilla seleccionada
    setColors(0, 13);

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

                setColors(0, 14);
                ventana(cursorX, cursorY, 10, 6, 0);

                posActualX --;
                cursorY -= 7;

                if(hayFichaSeleccionada && fichaSeleccionada <= 12){ // Si hay ficha seleccionada, el puntero sera blanco, sino, azul
                    setColors(0, 15);
                }else{
                    setColors(0, 13);
                }
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

                setColors(0, 14);
                ventana(cursorX, cursorY, 10, 6, 0);

                posActualX ++;
                cursorY += 7;

                if(hayFichaSeleccionada && fichaSeleccionada <= 12){ // Si hay ficha seleccionada, el puntero sera blanco, sino, azul
                    setColors(0, 15);
                }else{
                    setColors(0, 13);
                }
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 77:
            // Derecha
            if(cursorX < 92){
                setColors(0, 14);
                ventana(cursorX, cursorY, 10, 6, 0);

                posActualY ++;
                cursorX += 11;

                if(hayFichaSeleccionada && fichaSeleccionada <= 12){ // Si hay ficha seleccionada, el puntero sera blanco, sino, azul
                    setColors(0, 15);
                }else{
                    setColors(0, 13);
                }
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 75:
            // Izquierda
            if(cursorX > 0){
                setColors(0, 14);
                ventana(cursorX, cursorY, 10, 6, 0);

                posActualY --;
                cursorX -= 11;
                if(hayFichaSeleccionada && fichaSeleccionada <= 12){ // Si hay ficha seleccionada, el puntero sera blanco, sino, azul
                    setColors(0, 15);
                }else{
                    setColors(0, 13);
                }
                ventana(cursorX, cursorY, 10, 6, 0);
            }
            break;
        case 13: // Pulsamos ENTER

            if(!hayFichaSeleccionada){
                fichaSeleccionada = tablero[posActualX + 6][posActualY];
                posFichaSeleccionadaX = posActualX + 6;
                posFichaSeleccionadaY = posActualY;
                cursorPosAnteriorX = cursorX;
                cursorPosAnteriorY = cursorY;

                /* This will not crash anymore! :D */
                if(fichaSeleccionada <= 12 && fichaSeleccionada > 0 && fichaSeleccionada != 11 && fichaSeleccionada != 12){

                    //C'mon con las comprobaciones

                    //Ya sabemos que la ficha es menor a 12, so... es nuestra ^^
                    hayFichaSeleccionada = true;  //Tenemos una ficha en la "mano"
                    cursorPos(115, 5);

                    if(hayFichaSeleccionada){

                            //Ponemos color blanco
                            setColors(0, 15);
                            //Repintamos el cuadrado actual en el color de arriba
                            ventana(cursorX, cursorY, 10, 6, 0);

                            cursorPos(115, 5);
                            logs(2); // Log 2 -> Ficha seleccionada   ->>>>>>> Aqui estaba el bug que hacia crashear el juego! :D ( "La llamada del bug" )

                    }


               }else{
                    if(fichaSeleccionada == 999){//Estamos pinchando en el agua
                        logs(4);
                    }else if(fichaSeleccionada == 0){
                        logs(5); // Log 5 -> Hueco vacio!
                    }else if(fichaSeleccionada == 11){
                        logs(6); // Log 6 -> Bomba
                    }else if(fichaSeleccionada == 12){
                        logs(7); // Log 6 -> Bandera
                    }else{
                        logs(3); // Log 3 -> No puedes usar la ficha del oponente
                    }
               }

            }else{

                int posFichaDestinoX = posActualX + 6;
                int posFichaDestinoY = posActualY;

                if(fichaSeleccionada == 9){ //Explorador
                    //Comprobar con un FOR que desde X INI -> X FIN las casillas == 0
                    //TODO

                    // Lo dejo asi temporalmente (Podremos saltar fichas del enemigo)

                    if(tablero[posActualX + 6][posActualY] == 0){
                        tablero[posActualX + 6][posActualY] = fichaSeleccionada; // Ponemos la ficha nueva al valor de la ficha
                    }else if(tablero[posActualX + 6][posActualY] >= 100){
                        int valorAtacante = fichaSeleccionada;
                        compruebaCombate(1, valorAtacante, posFichaSeleccionadaX, posFichaSeleccionadaY, posActualX + 6, posActualY);
                    }

                    tablero[posFichaSeleccionadaX][posFichaSeleccionadaY] = 0; // Ponemos la ficha anterior a 0;
                    hayFichaSeleccionada = false;

                    //Si llegamos hasta aqui, pasamos el turno al PC;
                    turno *= -1;
                    pintaParrilla();


                }else if(posFichaSeleccionadaX - posFichaDestinoX == 1 && posFichaSeleccionadaY - posFichaDestinoY == 0){

                    if(tablero[posActualX + 6][posActualY] == 0){
                        tablero[posActualX + 6][posActualY] = fichaSeleccionada; // Ponemos la ficha nueva al valor de la ficha
                    }else if(tablero[posActualX + 6][posActualY] >= 100){
                        int valorAtacante = fichaSeleccionada;
                        compruebaCombate(1, valorAtacante, posFichaSeleccionadaX, posFichaSeleccionadaY, posActualX + 6, posActualY);
                    }

                    tablero[posFichaSeleccionadaX][posFichaSeleccionadaY] = 0; // Ponemos la ficha anterior a 0;
                    hayFichaSeleccionada = false;

                    //Si llegamos hasta aqui, pasamos el turno al PC;
                    turno *= -1;
                    pintaParrilla();

                }else{
                    logs(8); //No puedes mover tantas posiciones
                }

            }


            break;
    }

    pintaCasillasInaccesibles();

}

void movimientoPC(){
    int posFichaPCX;
    //Obtenemos una ficha random
    if(fichasMovidas1aFilaPC < 5){
        posFichaPCX = 3;
    }else if(fichasMovidas1aFilaPC >= 5){
        posFichaPCX = aleatorio(2);
        printf("%d, %d", fichasMovidas1aFilaPC, posFichaPCX);
        if(posFichaPCX == 0){
            posFichaPCX = 3;    //Nota mental -> Soy retrasado (20 minutos, sin ver que estaba haciendo una comparacion en lugar de una asignacion)
        }else if(posFichaPCX == 1){
            posFichaPCX = 2;
        }
    }

    int posFichaPCY = aleatorio(10);

    int fichaPC = tablero[posFichaPCX][posFichaPCY];

    if(fichaPC == 111 || fichaPC == 112 || fichaPC <= 12){
        movimientoPC();
    }else{


        if(tablero[posFichaPCX + 1][posFichaPCY ] == 0){ // Si la posicion inferior de esa casilla esta vacia

            //Movemos la ficha
            int fichaPCAMover = tablero[posFichaPCX][posFichaPCY];
            tablero[posFichaPCX][posFichaPCY] = 0;
            tablero[posFichaPCX + 1][posFichaPCY] = fichaPCAMover;
            fichasMovidas1aFilaPC++;

            pintaParrilla();

            //Si llegamos hasta aqui, pasamos el turno al PC;
            turno *= -1;

        }else if(tablero[posFichaPCX][posFichaPCY + 1] == 0 || tablero[posFichaPCX][posFichaPCY - 1] == 0){ // Comprobamos los laterales de la ficha
            if(tablero[posFichaPCX][posFichaPCY + 1] == 0){ // Sino, comprobamos si a la derecha esta vacia
                //Movemos la ficha
                int fichaPCAMover = tablero[posFichaPCX][posFichaPCY];
                tablero[posFichaPCX][posFichaPCY] = 0;
                tablero[posFichaPCX][posFichaPCY + 1] = fichaPCAMover;

                pintaParrilla();

                //Si llegamos hasta aqui, pasamos el turno al PC;
                turno *= -1;

            }else{ // Sino, por ultimo comprobamos si a la izquierda esta vacia
                //Movemos la ficha
                int fichaPCAMover = tablero[posFichaPCX][posFichaPCY];
                tablero[posFichaPCX][posFichaPCY] = 0;
                tablero[posFichaPCX][posFichaPCY - 1] = fichaPCAMover;

                pintaParrilla();

                //Si llegamos hasta aqui, pasamos el turno al PC;
                turno *= -1;

            }

        }else{ //Combate?

            if(tablero[posFichaPCX + 1][posFichaPCY ] <= 12){
                printf("%d - %d es igual a ", posFichaPCX+1, posFichaPCY, tablero[posFichaPCX + 1][posFichaPCY ]);
            }
        }


    }


    //Sleep(500);

}

void compruebaCombate(int turno, int valorAtacante, int posX_Inicio, int posY_Inicio, int posX_Destino, int posY_Destino){

    int atacante = tablero[posX_Inicio][posY_Inicio];
    int defensor = tablero[posX_Destino][posY_Destino];

    defensor -= 100; // Ya no tiene ventaja el PC! :D

    //cursor

    cursorPos(125, 30);
    //printf("%d vs %d ", atacante, defensor);
    //printf("POS: %d:%d(%d)  -> POS %d:%d(%d)", posX_Inicio, posY_Inicio,atacante, posX_Destino, posY_Destino, defensor);
    if(turno == 1){ // Usuario
        if(atacante > defensor){
            tablero[posX_Destino][posY_Destino] = atacante;
            printf("Combate! %d vs %d gana atacante", atacante, defensor);
            pintaParrilla();
        }else{
            tablero[posX_Inicio][posY_Inicio] = defensor;
            printf("Combate! %d vs %d gana defensor", atacante, defensor);
            pintaParrilla();
        }
    }else{

    }
}

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


        /* Peque�o debug de array */
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

void logs(int log){

    //Color Rojo-Debug
    setColors(0, 13);
    //Dibujamos ventana de debug
    ventana(112, 34, 42, 5, 0);
    cursorPos(125, 34);
    printf(" Eventos ");


    cursorPos(113, 36);
    // Limpio de forma cutrilla la linea, para que no se solapen los nombres
    printf("                         ");
    cursorPos(113, 36);
    switch(log){
        case 1: // Log de inicio de partida
            printf("Partida iniciada");
        break;
        case 2: // Log de la ficha seleccionada
            printf("Ficha seleccionada: %s (%d)", nombreFicha(tablero[posActualX + 6][posActualY]), tablero[posActualX + 6][posActualY]); //--> Something is bugged here! :O
        break;
        case 3:
            printf("No puedes usar la ficha del oponente");
        break;
        case 4:
            printf("Hold your horses! This is Agua!");
        break;
        case 5:
            printf("Esta posicion esta vacia!");
        break;
        case 6:
            printf("No puedes mover la bomba!");
        break;
        case 7:
            printf("No puedes mover la bandera!");
        break;
        case 8:
            printf("No puedes mover a esa casilla!");
        break;
    }

}

void logFichas(){
    setColors(0, 13);
    //Dibujamos ventana de debug
    ventana(112, 20, 42, 13, 0);
    cursorPos(120, 20);
    printf(" Fichas en el tablero ");




}

void juego(int tipoInicio){
    ventanaConsola(155,73, "iJoStratego");
    logs(1); //Log 1 -> Partida Iniciada



    if(tipoInicio == 1){
        //Iniciamos la jugada Defensiva
        setFichas(1);
    }else if(tipoInicio == 2){
        //Iniciamos la jugada Agresiva
        setFichas(2);
    }else if(tipoInicio == 3){
        //Ponemos las fichas a mano
        setFichas(3);
    }

    pintaParrilla();
    logFichas();

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

        // Este metodo controla el movimiento del cursor
        //pintaNombreFicha(fichasJugador[posActualX][posActualY]);

        if(turno == 1){ //Turno 1 = Persona; -1 = PC
            movimientoCursor();
        }else{
            movimientoPC();
        }



    }while(seEstaJugando);


}

int main(){

    //De momento llamamos al juego y no al menu.

    juego(1);
    //menu();

}
