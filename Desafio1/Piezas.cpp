#include "piezas.h"

const int I_ALTO = 4, I_ANCHO = 1;
const int O_ALTO = 2, O_ANCHO = 2;
const int T_ALTO = 2, T_ANCHO = 3;
const int S_ALTO = 3, S_ANCHO = 2;
const int Z_ALTO = 3, Z_ANCHO = 2;
const int J_ALTO = 3, J_ANCHO = 2;
const int L_ALTO = 3, L_ANCHO = 2;

unsigned short I[6] = {
    0b000000,
    0b001000,
    0b001000,
    0b001000,
    0b001000,
    0b000000
};

unsigned short O[6] = {
    0b000000,
    0b000000,
    0b001100,
    0b001100,
    0b000000,
    0b000000
};

unsigned short T[6] = {
    0b000000,
    0b000000,
    0b011100,
    0b001000,
    0b000000,
    0b000000
};

unsigned short S[6] = {
    0b000000,
    0b000000,
    0b001000,
    0b001100,
    0b000100,
    0b000000
};

unsigned short Z[6] = {
    0b000000,
    0b000000,
    0b000100,
    0b001100,
    0b001000,
    0b000000
};

unsigned short J[6] = {
    0b000000,
    0b000000,
    0b000100,
    0b000100,
    0b001100,
    0b000000
};

unsigned short L[6] = {
    0b000000,
    0b000000,
    0b001000,
    0b001000,
    0b001100,
    0b000000
};


void generarO(unsigned int* tablero, int X){         //Generar
    tablero[0] = 0b11<<(X);
    tablero[1] = 0b11<<(X);
}
void generarI(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X);
    tablero[1] = 0b1<<(X);
    tablero[2] = 0b1<<(X);
    tablero[3] = 0b1<<(X);
}
void generarT(unsigned int* tablero, int X){
    tablero[0] = 0b111<<(X);
    tablero[1] = 0b1<<(X+1);
}
void generarS(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X);
    tablero[1] = 0b11<<(X);
    tablero[2] = 0b1<<(X+1);
}
void generarZ(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X+1);
    tablero[1] = 0b11<<(X);
    tablero[2] = 0b1<<(X);
}
void generarJ(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X+1);
    tablero[1] = 0b1<<(X+1);
    tablero[2] = 0b11<<(X);
}
void generarL(unsigned int* tablero, int X){
    tablero[0] = 0b1<<(X);
    tablero[1] = 0b1<<(X);
    tablero[2] = 0b11<<(X);
}

