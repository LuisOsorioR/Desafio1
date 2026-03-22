#ifndef TABLERO_H
#define TABLERO_H

unsigned int* crearTablero(int altura);
unsigned int* crearRegistro(int altura);
void imprimir(int altura, int ancho,unsigned int* tablero, unsigned int* registro);
void registroTablero(unsigned int* tablero,unsigned int* registro, int altura);
void gameOver();
#endif // TABLERO_H
