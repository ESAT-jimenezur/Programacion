#include <stdio.h>
#include <conio.h>
#include <windows.h>


void cursorPos(int x, int y){
    COORD coor = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}


int main(){
    int x = 10;
    int y = 10;
    char c;


   do{

        cursorPos(x, y);

        printf("%c", 220);
        c = getch();

        if(c == 32){
            c = getch();
        }

        cursorPos(x, y);

        printf("%c", 32);

        switch (c){
            case 72:
                // Arriba
                y--;
                break;
            case 80:
                // Abajo
                y++;
                break;
            case 77:
                // Derecha
                x++;
                break;
            case 75:
                // Izquierda
                x--;
                break;
        }

    }while(c != 27);
}
