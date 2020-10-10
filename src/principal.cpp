//
// Created by francisco on 10/10/20.
//
#include <iostream>
using std::cout;
using std::endl;

#include "estructuras.h"
#include "impresiones.h"
#include "aritmetica.h"

int main(){

    cout << "Se empezo el TP1!!!" << endl;
    imprimirMenuPrincipal();
    InformacionJuego juegoNuevo = iniciarJuego();
    cargarGrilla(juegoNuevo.grillaJuego);
    cout << endl;
    imprimirGrilla(juegoNuevo.grillaJuego.grillaInicial);
    do {
        actualizarGrilla(juegoNuevo.grillaJuego);
        cout << endl << endl << endl;
        imprimirGrilla(juegoNuevo.grillaJuego.grilla);
    }while(avanzarTurno());

    return 0;
}
