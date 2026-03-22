#include <iostream>
#include <cstdlib>
#include "Sistema.h"
#include "tablero.h"

using namespace std;

bool rejugar = true, alturaValid, anchoValid, continuar = true, fichaActiva;
int altura = 0, ancho = 0, correccion, aleatorio;
unsigned int valorMax = 1;
unsigned int* tablero, *registro;

int main()
{
    srand(time(0));
    while(rejugar){
        continuar = true;
        alturaValid = false;
        anchoValid = false;

        cout << "Bienvenido a Tetris por turnos." << endl;
        while(alturaValid == false || anchoValid == false){
            while(alturaValid == false){
                cout << "Ingrese una altura valida para el tablero del tetris(minimo 8): ";
                cin >> altura;
                if(altura >= 8){
                    alturaValid = true;
                }
            }
            while(anchoValid == false){
                cout << "Ingrese un ancho valido para el tablero(minimo 8 y multiplo de 8): ";
                cin >> ancho;
                if(ancho >=8 && ancho%8 == 0){
                    anchoValid = true;
                }
            }
            cout << "Desea corregir algun dato?, ingrese - 1 - en caso tal: ";
            cin >> correccion;
            if(correccion == 1){
                alturaValid = false;
                anchoValid = false;
            }
        }
        tablero = crearTablero(altura);
        registro = crearRegistro(altura);

        for(int i = 1; i<=ancho; i++){
            valorMax *= 2;
        }
        valorMax -= 1;

        while(continuar){
            aleatorio = rand()%7;
            controles(tablero, registro, ancho, altura, aleatorio);
            verificacion(registro, altura, valorMax);
            continuar = estado(registro, tablero);
            rejugar = false;

        }
    }
}
