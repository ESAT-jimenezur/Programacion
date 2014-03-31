#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>



/** Un máximo de 100 restaurantes
        Cada uno, con un máximo de 5 salas
            Cada sala, un máximo de 50 mesas
                Cada mesa tiene asignado un numero y nombre de responsable
                    Cada sala tiene asignado un nombre de sala y un nombre de responsable
                        Cada Restaurante tiene asociado un nombre de restaurante y de responsable

    Los nombres son: nombre, apellido1 y apellido2
**/


struct Responsable{
    char nombre[80];
    char apellido1[80];
    char apellido2[80];
};

struct Mesa{
    int n_mesa;
    Responsable responsable_mesa;
};

struct Sala{
    char nombre_sala[80];
    Responsable responsable_sala;
    Mesa mesas[50];
};

struct Restaurante{
    char nombre_restaurante[80];
    Responsable responsable_restaurante;
    Sala salas[5];
};

    Restaurante restaurantes[100];


int main(){


    return 0;
}
