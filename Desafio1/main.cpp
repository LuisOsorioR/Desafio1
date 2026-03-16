#include <iostream>
#include "piezas.h"
#include "Sistema.h"
#include "tablero.h"

using namespace std;

bool rejugar = true, alturaValid, anchoValid;
int altura = 0, ancho = 0, correccion;

int main()
{
    while(rejugar){
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
    }
}
