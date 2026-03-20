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
unsigned int* crearRegistro(int altura){
    unsigned int* registro;
    registro = new unsigned int[altura];
    for(int i = 0; i < altura; i++){
        registro[i] = 0;
    }
    return registro;
}


void imprimir(int altura, int ancho,unsigned int* tablero, unsigned int* registro){

    cout << "      ______     __       _     " << endl
         << "     /_  __/__  / /______(_)____" << endl
         << "      / / / _ |/ __/ ___/ / ___/" << endl
         << "     / / /  __/ /_/ /  / (__  ) " << endl
         << "    /_/  |___/|__/_/  /_/____/  " << endl << endl;

    for(int i = 0; i<altura; i++){
        cout << "|";
        for(int j = 0; j<ancho; j++){
            if(((tablero[i] >> j) & 1) == 1){
                cout << "[]";
            }
            else if(((registro[i] >> j) & 1) == 1){
                    cout << "[]";
                }
            else{
                cout << " .";
            }
        }
        cout << "|" << endl;
    }

    cout << endl << "Accion:   [A]Izquierda   [D]Derecha   [S]Abajo   [W]Rotar   [Q]Salir" << endl;
}

void registroTablero(unsigned int* tablero,unsigned int* registro, int altura){
    for(int i = 0; i < altura; i++){
        registro[i] |= tablero[i];
    }
}
