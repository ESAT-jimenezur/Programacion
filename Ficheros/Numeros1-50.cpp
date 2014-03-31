#include <stdio.h>

FILE *fichero;


void rellenar(){

    fichero = fopen("Ficheros/numeros1_50.dat", "wb");

    for(int i = 10; i <= 20; i++){
        fwrite(&i , sizeof(int), 1, fichero);
    }

    fclose(fichero);
}

void leer(){
    fichero = fopen("Ficheros/numeros1_50.dat", "rb");

    int lectura = 0;
      while(!feof(fichero)){
          fread(&lectura,sizeof(int),1, fichero);
          if(!feof(fichero)){
            printf("%d ", lectura);
        }
      }


    fclose(fichero);
}

void cambiar(int n1, int n2){
    fichero = fopen("Ficheros/numeros1_50.dat", "r+b");

    while(!feof(fichero)){
        //fseek(fichero,  sizeof(int), 0);

        //TODO
        /*
        if(fse){

        }
        */
    }


    fclose(fichero);
}

void modificar_numero(){
    int n_modificar;
    int n_cambiar;

    printf("Que numero quieres modificar?\n");
    scanf("%d", n_modificar);
    printf("Por cual lo quieres cambiar?\n");
    scanf("%d", n_cambiar);
    printf("---------------------\n");
    cambiar(n_modificar, n_cambiar);
}

int main(){

    rellenar();

    leer();

    printf("---------------------\n");

    modificar_numero();

    return 0;
}
