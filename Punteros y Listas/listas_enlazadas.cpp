/*Quiero una lista que vaya de principio a fin de posicion en posicion
que me permita almacenar valores hasta 0 cuando mostrare todo lo que contiene*/

#include <stdio.h>

struct tnodo{
    int info;//variable que contiene la informacion
    tnodo *sigue;//puntero que dira la siguiente posicion
};

tnodo *p,*q;//puntero de principio de lista

//p=new(tnodo) me sirve para reservar el hueco para un nuevo enlace del tamaño de la structura.
//hay que ver el sitio al que apunta como un cojunto no en sus 2 partes o contenidos (info y siguiente)
//para acceder a un campo dentro de la estructura en vez del punto como con ficheros para punteros usaremos
// -> (como una flechita)


main (){
    p = NULL;

    do{ //CON ESTO VOY CREANDO LA LISTA ENLAZADA
        q = new(tnodo);
        printf("Valor: ");
        scanf("%d", &q -> info);
        if (q -> info != 0){
            q -> sigue = p;
            p = q;
        }

    }while(q -> info != 0);//cuando info valga 0 fin del do while

    for (q = p ; q!= NULL; q = q -> sigue){//esto recorre desde el inicio de hasta el final la lista
        printf("Informacion del nodo [%p] %d \n",q,q->info);//q muestra la posicion de memoria q->info muestra el valor que contiene
    }

}
