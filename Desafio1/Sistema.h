#ifndef SISTEMA_H
#define SISTEMA_H

void controles(unsigned int* tablero, unsigned int* registro, int ancho, int altura, int tipoPieza);

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
