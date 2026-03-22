#ifndef TABLERO_H
#define TABLERO_H

unsigned int* crearTablero(int altura);
unsigned int* crearRegistro(int altura);
void imprimir(int altura, int ancho,unsigned int* tablero, unsigned int* registro, int siguientePieza);
void registroTablero(unsigned int* tablero,unsigned int* registro, int altura);
void gameOver();
void impSigPie(int siguientePieza,int i);
#endif // TABLERO_H
