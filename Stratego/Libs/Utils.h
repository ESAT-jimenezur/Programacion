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
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 10; x++){
            array_A[x][y] = array_B[x][y];
        }
    }
}




