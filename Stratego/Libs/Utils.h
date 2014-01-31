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
        case 1:
            return "Mariscal";
            break;
        case 2:
            return "General";
            break;
        case 3:
            return "Coronel";
            break;
        case 4:
            return "Comandante";
            break;
        case 5:
            return "Capitan";
            break;
        case 6:
            return "Teniente";
            break;
        case 7:
            return "Sargento";
            break;
        case 8:
            return "Minero";
            break;
        case 9:
            return "Explorador";
            break;
        case 10:
            return "Espia";
            break;
        case 11:
            return "Bomba";
            break;
        case 12:
            return "Bandera";
            break;
    }
}


void asignaArray(int array_A[4][10], int array_B[4][10]){
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 10; x++){
            array_A[x][y] = array_B[x][y];
        }
    }
}




