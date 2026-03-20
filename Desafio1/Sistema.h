#ifndef SISTEMA_H
#define SISTEMA_H

void controlesL(unsigned int* tablero, unsigned int* registro, int ancho, int altura);
void DesplazarLizq(int Y, unsigned int* tablero);
void DesplazarLder(int Y, unsigned int* tablero);
int BajarL(int Y, unsigned int* tablero);

#endif // SISTEMA_H
