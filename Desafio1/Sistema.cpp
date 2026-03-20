#include <iostream>
#include "sistema.h"
#include "piezas.h"
#include "Tablero.h"
using namespace std;

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
            colisionX = colisionHorizontalDer(Y, ancho, alturaI, anchoI, tablero, registro);
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
        if(accion == 'Q' || Y == altura-4 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);

}

void controlesO(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaO, anchoO;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaO = O_ALTO;
    anchoO = O_ANCHO;
    generarO(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaO, anchoO, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaO, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, alturaO, anchoO, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaO, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaO, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaO);
        if(accion == 'Q' || Y == altura-2 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);
}

void controlesS(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaS, anchoS;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaS = S_ALTO;
    anchoS = S_ANCHO;
    generarS(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaS, anchoS, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaS, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, alturaS, anchoS, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaS, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaS, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaS);
        if(accion == 'Q' || Y == altura-3 || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);
}

void controlesZ(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaZ, anchoZ;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaZ = Z_ALTO;
    anchoZ = Z_ANCHO;
    generarZ(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaZ, anchoZ, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaZ, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, alturaZ, anchoZ, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaZ, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaZ, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaZ);
        if(accion == 'Q' || Y == altura-alturaZ || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);
}

void controlesT(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaT, anchoT;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaT = T_ALTO;
    anchoT = T_ANCHO;
    generarT(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y, alturaT, anchoT, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaT, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, alturaT, anchoT, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaT, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaT, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaT);
        if(accion == 'Q' || Y == altura-alturaT || colisionY == true){
            break;
        }
    }
    registroTablero(tablero, registro, altura);
}
void controlesJ(unsigned int* tablero, unsigned int* registro, int ancho, int altura){
    char accion;
    int X, Y, alturaJ, anchoJ;
    bool colisionY = false, colisionX;
    X = ancho/2;
    Y = 0;
    alturaJ = J_ALTO;
    anchoJ = J_ANCHO;
    generarL(tablero, X);
    while(!colisionY){
        imprimir(altura, ancho, tablero, registro);
        cin >> accion;
        switch(accion){
        case 'A':
        case 'a':
            colisionX = colisionHorizontalIzq(Y,alturaJ, anchoJ, tablero, registro);
            if(!colisionX){
                DesplazarIzq( Y, alturaJ, tablero);
            }
            break;
        case 'D':
        case 'd':
            colisionX = colisionHorizontalDer(Y, ancho, alturaJ, anchoJ, tablero, registro);
            if(!colisionX){
                DesplazarDer(Y, alturaJ, tablero);
            }
            break;
        case 'S':
        case 's':
            Y = Bajar(Y, alturaJ, tablero);
            break;
        }
        colisionY = colisionVertical(Y, tablero, registro, alturaJ);
        if(accion == 'Q' || Y == altura-alturaJ || colisionY == true){
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
            colisionX = colisionHorizontalDer(Y, ancho, alturaL, anchoL, tablero, registro);
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
