#include <iostream>
#include "sistema.h"
#include "piezas.h"
#include "Tablero.h"
const int Y = 0;

using namespace std;
/*bool colisionVerticalL(int Y, unsigned int* tablero){
    bool colision;
    if((tablero[Y+2] & tablero[Y+3]) != 0){
        colision = true;
    } else{
        colision = false;
    }
    return colision;
}*/


void DesplazarLizq(int Y, unsigned int* tablero){
    tablero[Y] = tablero[Y]>>1;
    tablero[Y+1] = tablero[Y+1]>>1;
    tablero[Y+2] = tablero[Y+2]>>1;
}
void DesplazarLder(int Y, unsigned int* tablero){
    tablero[Y] = tablero[Y]<<1;
    tablero[Y+1] = tablero[Y+1]<<1;
    tablero[Y+2] = tablero[Y+2]<<1;
}
int BajarL(int Y, unsigned int* tablero){
    tablero[Y+3] = tablero[Y+2];
    tablero[Y+2] = tablero[Y+1];
    tablero[Y+1] = tablero[Y];
    tablero[Y] = 0;
    Y += 1;
    return Y;
}




void controlesL(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y;
    bool colisionY=false, colisionX;
    X = ancho/2;
    Y = 0;
    generarL(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            DesplazarLizq( Y, tablero);
            break;
        case 'D':
        case 'd':
            DesplazarLder(Y, tablero);
            break;
        case 'S':
        case 's':
            Y = BajarL(Y, tablero);
            break;
        }
        if(accion == 'Q' || Y == altura-3){
            break;
        }
    }
    registroTablero(tablero, registro, altura);

}
