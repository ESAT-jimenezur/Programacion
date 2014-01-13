// Este fichero tiene que estar incluido en la carpeta del Stratego (junto a Stratego.cpp)
// Ademas tendremos que configurarlo en el compilador.


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

char *nombreFicha(int ficha){
    switch (ficha){
        case 2:
            return "TEST";
            break;
    }
}


void asignaArray(int array_A[10][4], int array_B[10][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            array_A[i][j] = array_B[i][j];
        }
    }
}




