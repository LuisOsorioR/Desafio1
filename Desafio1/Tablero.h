#ifndef TABLERO_H
#define TABLERO_H

unsigned int* crearTablero(int altura);
unsigned int* crearRegistro(int altura);
void imprimir(int altura, int ancho,unsigned int* tablero, unsigned int* registro);
unsigned int* registroTablero(unsigned int* tablero,unsigned int* registro, int altura);

#endif // TABLERO_H
