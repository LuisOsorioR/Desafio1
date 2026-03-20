#ifndef SISTEMA_H
#define SISTEMA_H

void controlesI(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesO(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesT(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesS(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesZ(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesJ(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesL(unsigned int* tablero, unsigned int* registro, int ancho, int altura);

void DesplazarLizq(int Y, unsigned int* tablero);
void DesplazarLder(int Y, unsigned int* tablero);
int BajarL(int Y, unsigned int* tablero);

bool colisionVertical(int Y, unsigned int* tablero, unsigned int* registro, int alturaFig);
bool colisionHorizontalIzq(int Y, int alturaFig, int X, int anchoFig, unsigned int* tablero, unsigned int* registro);
bool colisionHorizontalDer(int Y, int ancho, int alturaFig, int anchoFig, unsigned int* tablero, unsigned int* registro);

bool estado(unsigned int* registro, unsigned int* tablero);
void verificacion(unsigned int* registro, int altura, unsigned int valorMax);
void eliminarFila(unsigned int* registro, int altura);
#endif // SISTEMA_H
