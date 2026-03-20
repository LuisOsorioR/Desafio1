#include "piezas.h"

const int I_ALTO = 4, I_ANCHO = 1;
const int O_ALTO = 2, O_ANCHO = 2;
const int T_ALTO = 2, T_ANCHO = 3;
const int S_ALTO = 3, S_ANCHO = 2;
const int Z_ALTO = 3, Z_ANCHO = 2;
const int J_ALTO = 3, J_ANCHO = 2;
const int L_ALTO = 3, L_ANCHO = 2;

unsigned short I[4] = {
    0b1,
    0b1,
    0b1,
    0b1
};

unsigned short O[2] = {
    0b11,
    0b11
};

unsigned short T[2] = {
    0b111,
    0b010
};

unsigned short S[3] = {
    0b10,
    0b11,
    0b01
};

unsigned short Z[3] = {
    0b01,
    0b11,
    0b10
};

unsigned short J[3] = {
    0b01,
    0b01,
    0b11
};

unsigned short L[3] = {
    0b10,
    0b10,
    0b11
};


void generarL(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X-1);
    tablero[1] = 0b1<<(X-1);
    tablero[2] = 0b11<<(X-1);
}

