#ifndef SISTEMA_H
#define SISTEMA_H

void controlesL(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void controlesI(unsigned int* tablero, unsigned int* registro, int ancho, int altura);

void DesplazarLizq(int Y, unsigned int* tablero);
void DesplazarLder(int Y, unsigned int* tablero);
int BajarL(int Y, unsigned int* tablero);

bool colisionVertical(int Y, unsigned int* tablero, unsigned int* registro, int alturaFig);
bool colisionHorizontalIzq(int Y, int alturaFig, int X, int anchoFig, unsigned int* tablero, unsigned int* registro);
#endif // SISTEMA_H
