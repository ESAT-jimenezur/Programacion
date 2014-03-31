#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>




/** Un máximo de 50 cadenas
        Un máximo de 80 caracteres cada cadena
**/


const int max = 50;

struct PilaDeCadenas{
    char cadena[max][80];
    int top;
};

PilaDeCadenas pila;

void crearPila(PilaDeCadenas &p){

}

bool esVacia(PilaDeCadenas &p){

}

void insertar(PilaDeCadenas &p, char linea[80]){

}



void getPila(PilaDeCadenas &p, int x){
    printf("%c", p.cadena[x]);
    getch();
}


void GetPila_FIFO(PilaDeCadenas &p, char linea[80]){
    if(!esVacia(p)){
        strcpy(linea, p.cadena[0]);
        for(int i = 0; i < p.top - 1; i++){
           // strcpy(p.cadena[i], )
        }
    }

}





//   strcpy(c1, c2) Copia la cadena2 en la cadena1


int main(){
    return 0;
}



