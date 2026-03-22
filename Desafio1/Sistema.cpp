#include <iostream>
#include "sistema.h"
#include "piezas.h"
#include "Tablero.h"
using namespace std;

void rotacion(int X,int Y,int altoPieza, int anchoPieza, unsigned int* tablero){
    unsigned int copia[4];
    int bit, suma;
    for(int i = 0; i < anchoPieza; i++){
        suma = 0;
        for(int j = 0; j < altoPieza; j++){
            bit = (tablero[Y + j] >> (X + i)) & 1;
            suma |= (bit << (altoPieza - 1 - j));
        }
        copia[i] = suma;
    }
    for(int j = 0; j < altoPieza; j++){
        tablero[Y + j] = 0;
    }
    for(int i = 0; i < anchoPieza; i++){
        tablero[Y + i] = copia[i] << X;
    }
}


void eliminarFila(unsigned int* registro, int altura){
    for(int i = altura; i > 0; i--){
        registro[i] = registro[i-1];
    }
    registro[0] = 0;
}

void verificacion(unsigned int* registro, int altura, unsigned int valorMax){
    for(int i = 0; i < altura; i++){
        if(registro[i] == valorMax){
            eliminarFila(registro, i);
            i--;
        }
    }
}


bool estado(unsigned int* registro, unsigned int* tablero){
    if((registro[1] & tablero[0])!= 0){
        return false;
    }return true;
}




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
            } else if((tablero[Y+j] & 1) != 0){
                return true;
            }
        }
    }
    return false;
}

bool colisionHorizontalDer(int Y, int ancho, int alturaFig, int anchoFig, unsigned int* tablero, unsigned int* registro){
    for (int j = 0 ; j < alturaFig ; j++){
        for(int i = 0; i < anchoFig ; i++){
            if(((tablero[Y+j]<<(1)) & registro[Y+j]) != 0){
                return true;
            } else if((tablero[Y+j] & 1 << (ancho-1)) != 0){
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
    for(int j=alturaFig; j>=0 ; j--){
        tablero[Y+j+1] = tablero[Y+j];
    }
    tablero[Y]=0;
    Y+=1;
    return Y;
}

void controles(unsigned int* tablero, unsigned int* registro, int ancho, int altura, int tipoPieza) {
    char accion;
    int X = ancho / 2 - 1;
    int Y = 0;
    int altoPieza=0, anchoPieza=0, aux=0;
    bool colisionY = false, colisionX;

    switch(tipoPieza) {
    case 0:
        altoPieza = L_ALTO;
        anchoPieza = L_ANCHO;
        generarL(tablero, X);
        break;
    case 1:
        altoPieza = I_ALTO;
        anchoPieza = I_ANCHO;
        generarI(tablero, X);
        break;
    case 2:
        altoPieza = O_ALTO;
        anchoPieza = O_ANCHO;
        generarO(tablero, X);
        break;
    case 3:
        altoPieza = S_ALTO;
        anchoPieza = S_ANCHO;
        generarS(tablero, X);
        break;
    case 4:
        altoPieza = Z_ALTO;
        anchoPieza = Z_ANCHO;
        generarZ(tablero, X);
        break;
    case 5:
        altoPieza = T_ALTO;
        anchoPieza = T_ANCHO;
        generarT(tablero, X);
        break;
    case 6:
        altoPieza = J_ALTO;
        anchoPieza = J_ANCHO;
        generarJ(tablero, X);
        break;
    }
    while(!colisionY) {
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion) {
        case 'W':
        case 'w':
            rotacion(X,Y,altoPieza,anchoPieza,tablero);
            aux = altoPieza;
            altoPieza = anchoPieza;
            anchoPieza = aux;
            break;
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, altoPieza, anchoPieza, tablero, registro);
            if(!colisionX){
                DesplazarIzq(Y, altoPieza, tablero);
                X -= 1;
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, altoPieza, anchoPieza, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, altoPieza, tablero);
                X += 1;
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, altoPieza, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, altoPieza);
        if(accion == 'Q' || accion == 'q' || Y == (altura - altoPieza) || colisionY == true) {
            break;
        }
    }
    registroTablero(tablero, registro, altura);
}
