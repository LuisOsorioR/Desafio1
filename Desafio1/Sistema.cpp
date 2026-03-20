#include <iostream>
#include "sistema.h"
#include "piezas.h"
#include "Tablero.h"


using namespace std;
/*bool colisionVertical(int Y, unsigned int* tablero, unsigned int* registro, int alturaFig){
    bool colision;
    if((tablero[Y+alturaFig] & registro[Y+alturaFig+1]) != 0){
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
    int X, Y, alturaL;
    bool colisionY=false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaL = L_ALTO;
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
        //colisionY = colisionVertical(Y, tablero, registro, alturaL);
        if(accion == 'Q' || Y == altura-3 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);
    tablero[altura]=0;

}
