#include <iostream>
#include "sistema.h"
#include "piezas.h"
#include "Tablero.h"


using namespace std;
bool colisionVertical(int Y, unsigned int* tablero, unsigned int* registro, int alturaFig){
    for(int i = 0; i < alturaFig; i++){
        if( (tablero[Y + i]) & registro[Y + i + 1] ){
            return true;
        }
    }
    return false;
}

bool colisionHorizontalIzq(int Y, int alturaFig, int anchoFig, unsigned int* tablero, unsigned int* registro){
    for (int j = 0 ; j < alturaFig ; j++){
        for(int i = 0; i < anchoFig ; i++){
            if(((tablero[Y+j]>>(1)) & registro[Y+j]) != 0){
                return true;
            }
        }
    }
    return false;
}

bool colisionHorizontalDer(int Y, int alturaFig, int anchoFig, unsigned int* tablero, unsigned int* registro){
    for (int j = 0 ; j < alturaFig ; j++){
        for(int i = 0; i < anchoFig ; i++){
            if(((tablero[Y+j]<<(1)) & registro[Y+j]) != 0){
                return true;
            }
        }
    }
    return false;
}


void DesplazarIzq(int Y, int alturaFig, unsigned int* tablero){
    for(int j=0; j<alturaFig;j++){
        tablero[Y+j] = tablero[Y+j] >> 1;
    }
}
void DesplazarDer(int Y, int alturaFig, unsigned int* tablero){
    for(int j=0; j<alturaFig;j++){
        tablero[Y+j] = tablero[Y+j] << 1;
    }
}
int Bajar(int Y, int alturaFig,unsigned int* tablero){
    for(int j=alturaFig; j>0 ; j--){
        tablero[Y+j+1] = tablero[Y+j];
    }
    tablero[Y]=0;
    Y+=1;
    return Y;
}


void controlesI(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaI, anchoI;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaI = I_ALTO;
    anchoI = I_ANCHO;
    generarI(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaI, anchoI, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaI, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, alturaI, anchoI, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaI, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaI, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaI);
        if(accion == 'Q' || Y == altura-3 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);

}


void controlesL(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaL, anchoL;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaL = L_ALTO;
    anchoL = L_ANCHO;
    generarL(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaL, anchoL, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaL, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, alturaL, anchoL, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaL, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaL, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaL);
        if(accion == 'Q' || Y == altura-3 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);

}
