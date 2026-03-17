#include <iostream>
#include "Tablero.h"

using namespace std;

unsigned int* crearTablero(int altura){
    unsigned int* tablero;
    tablero = new unsigned int[altura];
    for(int i = 0; i < altura; i++){
        tablero[i] = 0;
    }
    return tablero;
}


void imprimir(int altura, int ancho,unsigned int* tablero){
    for(int i = 0; i<altura; i++){
        tablero[i] = 0;
        for(int j = 0; j<ancho; j++){
            if(((tablero[i] >> j) & 1) == 1){
                cout << "[]";
            }
            else{
                cout << " .";
            }
        }
        cout << endl;
    }
}
