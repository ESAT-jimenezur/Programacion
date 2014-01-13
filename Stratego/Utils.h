
/**************************************************
    Metodo que devuelve un error, según su codigo
    @get int e
    @return string error
**************************************************/
void error(int e){

}


/**************************************************
    Metodo que devuelve el nombre de una ficha,
    segun su numero
    @get int ficha
    @return string nombre
**************************************************/

void nombreFicha(int ficha){

    switch (ficha){

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
        partidaGanada = true;
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

