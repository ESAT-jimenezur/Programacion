#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
    funcion mostrar lista que provocara volcado por pantalla del contenido de la lista
    funcion insertar lista que metere una lista y un valor y lo pondra en dicha lista
    funcion extraer lista que extreae el elemento del elemento de la lista segun un LIFO
    funcion longitud lista que devuelve el numero de elemento que contiene la lista
    funcion es vacia lista que dice si esta vacia o no (verdadero o falso)
    funcion buscar lista que busca un elemento dentro de la lista y deja un elemento apuntando ahi si lo encuentra.
    funcion eliminar que se encarga de burcar un elemento de una lista y borrarlo.
    si pongo el (*&nombrepuntero) asi podremos trabajar
**/

struct tnodo{
    int data;//variable que contiene la informacion
    tnodo *next;//puntero que dira la siguiente posicion
};

tnodo *lista1, *lista2, *p;

void menu();

void insertar_lista(tnodo *&lista, int valor){
        tnodo *nuevo_nodo;
        nuevo_nodo = new(struct tnodo);
        nuevo_nodo -> data = valor;
        nuevo_nodo -> next = lista;
        lista = nuevo_nodo ;
}

void mostrar_lista(tnodo *lista){
    printf("------------------ Inicio de la lista ---------------------------------- \n");
    for (p = lista ; lista!= NULL; lista = lista -> next){//esto recorre desde el inicio de hasta el final la lista
        printf("Informacion del nodo [%p] %d \n", lista , lista -> data);//q muestra la posicion de memoria q->info muestra el valor que contiene
    }
    printf("------------------ Final de la lista alcanzado ------------------------- \n");
    getch();
}

void crear_lista(tnodo *&lista){
    lista = NULL;
    lista = new(tnodo);
}

int esVacia(tnodo *lista){
    return lista == NULL;
}

void menu(){

    int elec;


    do{
        system("cls");
        printf("******* iJosListas *******\n\n\n");

        //printf("%d -- %d \n\n", lista1, lista2);
        //printf("%d -- %d \n\n", lista1 -> next, lista2 -> next);
        //printf("%d \n\n", p);

        printf("1.- Insertar elemento en la lista\n");
        printf("2.- Mostrar lista\n");
        printf("6.- Salir \n");

        scanf("%d", &elec);


        switch(elec){
            case 1:
                int valor;
                printf("Que valor quieres introducir?\n");
                scanf("%d", &valor);
                //scanf("%d", &lista1 -> data);
                insertar_lista(lista1, valor);
                break;
            case 2:
                mostrar_lista(lista1);
                break;
            case 3:
                //modifica_contacto();
                break;
            case 4:
                //consulta_contacto();
                break;
            case 5:
                //lista_contactos();
                break;
            case 6:
                return;
        }

    }while(elec != 6);


}


int main(){

    /*
    p = NULL;
    q = new(tnodo);
    */



    crear_lista(lista1);
    crear_lista(lista2);

    insertar_lista(lista1, 4);
    insertar_lista(lista1, 15);
    insertar_lista(lista1, 20);
    insertar_lista(lista1, 35);

    insertar_lista(lista2, 10001);
    insertar_lista(lista2, 10010);
    insertar_lista(lista2, 10011);
    insertar_lista(lista2, 10100);


    menu();

    /*
    p = NULL;

    insertar_lista(p, 1);

    mostrar_lista(p);
    */
    return 0;
}
