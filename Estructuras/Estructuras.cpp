#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct FechaNacimiento{
    int diaNacimiento;
    int mesNacimiento;
    int anyoNacimiento;
}


struct Persona{
    char nombre[80];
    char apellido1[80];
    char apellido2[80];
    char direccion[80];
    char telefono[15];
    char email[15];
    FechaNacimiento fecha_nacimiento;
}

Persona agenda[100];


int nacidosAntesOEnElAnyo(int anyo){
    int total;
    for(int i = 0; i < 100; i++){
        if(agenda[i].fecha_nacimiento.anyoNacimiento <= anyo){
            total++;
        }
    }
    return total;
}


void buscarNombre(){
    for(int i = 0; i < 100; i++){
        if(strcmp(strupr(agenda[i].nombre), "ANTONIO")){
           printf("Nombre: ");
           fputs(agenda[i].nombre, stdout);

            printf("\n");

           printf("Primer Apellido: ");
           fputs(agenda[i].apellido1, stdout);

            printf("\n");

           printf("Segundo Apellido: ");
           fputs(agenda[i].apellido2, stdout);
        }
    }
}









int main(){

}
