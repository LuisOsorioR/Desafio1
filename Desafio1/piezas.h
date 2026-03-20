#ifndef PIEZAS_H
#define PIEZAS_H

extern unsigned short I[4];
extern unsigned short O[2];
extern unsigned short T[2];
extern unsigned short S[3];
extern unsigned short Z[3];
extern unsigned short J[3];
extern unsigned short L[3];


extern const int I_ALTO, I_ANCHO;
extern const int O_ALTO, O_ANCHO;
extern const int T_ALTO, T_ANCHO;
extern const int S_ALTO, S_ANCHO;
extern const int Z_ALTO, Z_ANCHO;
extern const int J_ALTO, J_ANCHO;
extern const int L_ALTO, L_ANCHO;

void generarI(unsigned int* tablero, int ancho);
void generarO(unsigned int* tablero, int ancho);
void generarT(unsigned int* tablero, int ancho);
void generarS(unsigned int* tablero, int ancho);
void generarZ(unsigned int* tablero, int ancho);
void generarJ(unsigned int* tablero, int ancho);
void generarL(unsigned int* tablero, int ancho);

#endif // PIEZAS_H
