/*--------------------------------*/
/*        iJos Public Lib         */
/*--------------------------------*/



/**       Funcion Sumar         **/
/**--------------------------------
    @Params float a;
            float b;
    @return float a + b
----------------------------------*/
float sumar(float a, float b){
    return a + b;
}


/**       Funcion Restar         **/
/**--------------------------------
    @Params float a;
            float b;
    @return float a - b
----------------------------------*/
float restar(float a, float b){
    return a - b;
}


/**       Funcion Factorial      **/
/**--------------------------------
    @Params float a;
    @return float a * factorial(a-1)
----------------------------------*/
float factorial(float a){
    if(a == 1){
        return 1;
    }else{
        return a * factorial(a - 1);
    }
}


/**       Funcion Potencia      **/
/**--------------------------------
    @Params float a;
            float b
    @return float c
----------------------------------*/
float potencia(float a, float b){
    if(b == 1){
        return a;
    }else{
        return a * potencia(a, b-1);
    }
}





/**--------------------------------
/**         U T I L S

    require:    <stdlib.h>
                <time.h>
                                **/
/**--------------------------------

/**       Create Seed            **/
/**------------------------------*/
void seed(){
    srand (time(NULL));
}


/**       Funcion aleatorio      **/
/**--------------------------------
    @return int a
----------------------------------*/

int aleatorio(int a){

    int b;
    b = (rand()% a);
    return b;

}





/**--------------------------------
/**         S C R E E N

    require:    <window.h>
--------------------------------**/
void colorTexto(int texto, int fondo){
    int color;

    color = (texto * 16) + fondo;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE));
}

void cursorPos(int x, int y){
    COORD coor = [x, y];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
}
