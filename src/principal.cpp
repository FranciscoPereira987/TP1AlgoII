//
// Created by francisco on 10/10/20.
//
#include <iostream>
using std::cout;
using std::endl;
#include "estructuras.h"
#include "impresiones.h"

int main(){

    cout << "Se empezo el TP1!!!" << endl;
    imprimirMenuPrincipal();
    InformacionJuego juegoNuevo = iniciarJuego();

    cout << juegoNuevo.totalMuertes << " Muertes"
    << endl;
    cout << juegoNuevo.totalNacimientos << " Nacimientos"
    <<endl;

    imprimirGrilla(juegoNuevo.grillaJuego.grilla);


    return 0;
}
