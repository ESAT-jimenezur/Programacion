<<<<<<< HEAD
#include <stdio.h>
#include <iJos.h>
#include<conio.h>
#include <string.h>

/*
    Altas
    Bajas
    Modificaciones
    Consultas
*/

struct Contacto{
    bool activo;
    char nombre[80];
    char primerApellido[80];
    char segundoApellido[80];
    char direccion[100];
    char provincia[80];
    char poblacion[80];


    char telefono1[80];
    char telefono2[80];

    //Falta fecha
};

FILE *fichero_agenda;

Contacto contacto;



void menu();


void pedirDatos(){

    system("cls");
    fflush(stdin);
    printf("*** Nuevo Contacto ***\n");
    printf("Introduce un nombre: ");
        scanf("%s", &contacto.nombre);
        fflush(stdin);

    printf("\nIntroduce el primer apellido: ");
        scanf("%s", &contacto.primerApellido);
        fflush(stdin);

    printf("\nIntroduce un segundo apellido: ");
        scanf("%s", &contacto.segundoApellido);
        fflush(stdin);

    printf("\nIntroduce la direccion: ");
        scanf("%s", &contacto.direccion);
        fflush(stdin);

    printf("\nIntroduce la provincia: ");
        scanf("%s", &contacto.provincia);
        fflush(stdin);

    printf("\nIntroduce la poblacion: ");
        scanf("%s", &contacto.poblacion);
        fflush(stdin);


    printf("\nIntroduce un telefono: ");
        scanf("%s", &contacto.telefono1);
        fflush(stdin);

    printf("\nIntroduce otro telefono: ");
        scanf("%s", &contacto.telefono2);
        fflush(stdin);

        //Activamos el contacto
        contacto.activo = true;
}

void alta_contacto(){

    char seguir;

    do{

        pedirDatos();
        fichero_agenda = fopen("Agenda/agenda.dat", "ab");
        fwrite(&contacto, sizeof(contacto), 1, fichero_agenda);
        fclose(fichero_agenda);
        printf("\n Quieres insertar otro contacto?\n S/N \n");
        seguir = getch();

    }while(seguir == 's');

    //menu();
}

void baja_contacto(){


}

void modifica_contacto(){

    system("cls");

    char nombre[80];
    char apellido[80];

    fichero_agenda = fopen("Agenda/agenda.dat", "wb");

    printf("\n ***************        Modificar Contacto        *************** \n\n");
    printf("Nombre del contacto a modificar: ");
    scanf("%s", nombre);
    fflush(stdin);
    nombre[strlen(nombre-1)]='\n';

    printf("Primer apellido del contacto a modificar: ");
    scanf("%s", apellido);
    fflush(stdin);

    int apuntador = 0;

    while(!feof(fichero_agenda)){
    fread(&contacto, sizeof(contacto), 1, fichero_agenda);
        if(!feof(fichero_agenda)){
                //printf("llega");
                printf("%d %d x %d = %d\n", apuntador, sizeof(contacto), apuntador, sizeof(contacto)*apuntador);
            if(strcmp(strlwr(nombre), strlwr(contacto.nombre)) == 0){
                //printf("Contacto encontrado, quieres modificarlo? s/n");
                fseek(fichero_agenda, sizeof(contacto) * (apuntador), SEEK_SET);
                pedirDatos();
                fwrite(&contacto, sizeof(contacto), 1, fichero_agenda);

            }else{
                //printf("No se ha encontrado el contacto");
            }

            //getch();

            apuntador++;
            getch();
        }

    }


    fclose(fichero_agenda);
    printf("\n *************** Pulsa cualquier tecla para salir *************** \n");
    getch();
    menu();

}

void consulta_contacto(){


}

void lista_contactos(){

    system("cls");

    fichero_agenda = fopen("Agenda/agenda.dat", "rb");

    printf("\n *************** Lista de Contactos *************** \n\n");


    while(!feof(fichero_agenda)){
    fread(&contacto, sizeof(contacto), 1, fichero_agenda);
    if(!feof(fichero_agenda)){
        printf("%s %s %s %s %s %s %s %s \n \n",
           contacto.nombre,
           contacto.primerApellido,
           contacto.segundoApellido,
           contacto.poblacion,
           contacto.provincia,
           contacto.direccion,
           contacto.telefono1,
           contacto.telefono2);
        }
    }


    fclose(fichero_agenda);
    printf("\n *************** Pulsa cualquier tecla para salir *************** \n");
    getch();
    menu();
}


void menu(){

    int elec;


    do{

        system("cls");
        printf("******* iJosGenda *******\n\n\n");
        printf("1.- Insertar nuevo contacto\n");
        printf("2.- Eliminar contacto\n");
        printf("3.- Modificar contacto\n");
        printf("4.- Buscar Contacto\n");
        printf("5.- Ver lista de contactos\n");
        printf("6.- Salir \n");

        scanf("%d", &elec);


        switch(elec){
            case 1:
                alta_contacto();
                break;
            case 2:
                baja_contacto();
                break;
            case 3:
                modifica_contacto();
                break;
            case 4:
                consulta_contacto();
                break;
            case 5:
                lista_contactos();
                break;
            case 6:
                return;
        }

    }while(elec != 6);


}

int main(){
    menu();
    return 0;
}
=======
#include <stdio.h>
#include <iJos.h>
#include<conio.h>
#include <string.h>

/*
    Altas
    Bajas
    Modificaciones
    Consultas
*/

struct Contacto{
    bool activo;
    char nombre[80];
    char primerApellido[80];
    char segundoApellido[80];
    char direccion[100];
    char provincia[80];
    char poblacion[80];


    char telefono1[80];
    char telefono2[80];

    //Falta fecha
};

FILE *fichero_agenda;

Contacto contacto;



void menu();


void pedirDatos(){

    system("cls");
    fflush(stdin);
    printf("*** Nuevo Contacto ***\n");
    printf("Introduce un nombre: ");
        scanf("%s", &contacto.nombre);
        fflush(stdin);

    printf("\nIntroduce el primer apellido: ");
        scanf("%s", &contacto.primerApellido);
        fflush(stdin);

    printf("\nIntroduce un segundo apellido: ");
        scanf("%s", &contacto.segundoApellido);
        fflush(stdin);

    printf("\nIntroduce la direccion: ");
        scanf("%s", &contacto.direccion);
        fflush(stdin);

    printf("\nIntroduce la provincia: ");
        scanf("%s", &contacto.provincia);
        fflush(stdin);

    printf("\nIntroduce la poblacion: ");
        scanf("%s", &contacto.poblacion);
        fflush(stdin);


    printf("\nIntroduce un telefono: ");
        scanf("%s", &contacto.telefono1);
        fflush(stdin);

    printf("\nIntroduce otro telefono: ");
        scanf("%s", &contacto.telefono2);
        fflush(stdin);

        //Activamos el contacto
        contacto.activo = true;
}

void alta_contacto(){

    char seguir;

    do{

        pedirDatos();
        fichero_agenda = fopen("Agenda/agenda.dat", "ab");
        fwrite(&contacto, sizeof(contacto), 1, fichero_agenda);
        fclose(fichero_agenda);
        printf("\n Quieres insertar otro contacto?\n S/N \n");
        seguir = getch();

    }while(seguir == 's');

    //menu();
}

void baja_contacto(){


}

void modifica_contacto(){

    system("cls");

    char nombre[80];
    char apellido[80];

    fichero_agenda = fopen("Agenda/agenda.dat", "wb");

    printf("\n ***************        Modificar Contacto        *************** \n\n");
    printf("Nombre del contacto a modificar: ");
    scanf("%s", nombre);
    fflush(stdin);
    nombre[strlen(nombre-1)]='\n';

    printf("Primer apellido del contacto a modificar: ");
    scanf("%s", apellido);
    fflush(stdin);

    int apuntador = 0;

    while(!feof(fichero_agenda)){
    fread(&contacto, sizeof(contacto), 1, fichero_agenda);
        if(!feof(fichero_agenda)){
                //printf("llega");
                printf("%d %d x %d = %d\n", apuntador, sizeof(contacto), apuntador, sizeof(contacto)*apuntador);
            if(strcmp(strlwr(nombre), strlwr(contacto.nombre)) == 0){
                //printf("Contacto encontrado, quieres modificarlo? s/n");
                fseek(fichero_agenda, sizeof(contacto) * (apuntador), SEEK_SET);
                pedirDatos();
                fwrite(&contacto, sizeof(contacto), 1, fichero_agenda);

            }else{
                //printf("No se ha encontrado el contacto");
            }

            //getch();

            apuntador++;
            getch();
        }

    }


    fclose(fichero_agenda);
    printf("\n *************** Pulsa cualquier tecla para salir *************** \n");
    getch();
    menu();

}

void consulta_contacto(){


}

void lista_contactos(){

    system("cls");

    fichero_agenda = fopen("Agenda/agenda.dat", "rb");

    printf("\n *************** Lista de Contactos *************** \n\n");


    while(!feof(fichero_agenda)){
    fread(&contacto, sizeof(contacto), 1, fichero_agenda);
    if(!feof(fichero_agenda)){
        printf("%s %s %s %s %s %s %s %s \n \n",
           contacto.nombre,
           contacto.primerApellido,
           contacto.segundoApellido,
           contacto.poblacion,
           contacto.provincia,
           contacto.direccion,
           contacto.telefono1,
           contacto.telefono2);
        }
    }


    fclose(fichero_agenda);
    printf("\n *************** Pulsa cualquier tecla para salir *************** \n");
    getch();
    menu();
}


void menu(){

    int elec;


    do{

        system("cls");
        printf("******* iJosGenda *******\n\n\n");
        printf("1.- Insertar nuevo contacto\n");
        printf("2.- Eliminar contacto\n");
        printf("3.- Modificar contacto\n");
        printf("4.- Buscar Contacto\n");
        printf("5.- Ver lista de contactos\n");
        printf("6.- Salir \n");

        scanf("%d", &elec);


        switch(elec){
            case 1:
                alta_contacto();
                break;
            case 2:
                baja_contacto();
                break;
            case 3:
                modifica_contacto();
                break;
            case 4:
                consulta_contacto();
                break;
            case 5:
                lista_contactos();
                break;
            case 6:
                return;
        }

    }while(elec != 6);


}

int main(){
    menu();
    return 0;
}
>>>>>>> 6c16e1b2701a29bd3393d5b478e2efe72c8e9b55
