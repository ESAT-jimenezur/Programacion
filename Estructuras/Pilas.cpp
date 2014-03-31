#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>



struct Conjunto{
    int cardinal;
    int elementos[50];
}

Conjunto conjunto;

struct Conjunto Union_Conjunto(struct Conjunto, struct Conjunto);
struct Conjunto Interseccion_Conjunto(struct Conjunto, struct Conjunto);


// Definir int Cardinal(struct Conjunto):int (Devuelve la posicion del elemento)
// Definir pertenece(Conjunto, int elemento):bool (Si esta o no en el conjunto)
// Incluir(struct Conjunto, int elemento):void (Añade el elemento al conjunto)
// Es vacio(Struct Conjunto):bool (Devuelve si el elemento esta vacio o no)



int main(){
    return 1;
}
