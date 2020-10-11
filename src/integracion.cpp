//
// Created by francisco on 10/10/20.
//
#include "estructuras.h"
#include "impresiones.h"
#include "aritmetica.h"

#include <iostream>

void reiniciarJuego(Tablero &grillas, EstadisticasTurno &estadisticas);
EstadisticasTurno presentarJuego(Tablero &grilla);
void jugar(InformacionJuego &juego, EstadisticasTurno estadisticas);

void juegoDeLaVida(){
    /*
     * Integra todo el programa
     */
    InformacionJuego juegoActual = iniciarJuego();
    EstadisticasTurno estadisticas = presentarJuego(juegoActual.grillaJuego);
    jugar(juegoActual, estadisticas);
}



EstadisticasTurno presentarJuego(Tablero &grillaJuego){
    /*
     * Presenta el juego y carga la grilla
     */
    EstadisticasTurno estadisticas;
    imprimirBienvenida();
    setearEstadisticasCero(estadisticas);
    estadisticas.cantidadVivas = cargarGrilla(grillaJuego); // Cargo la grilla

    return estadisticas;
}

void presentarEstadisticas(InformacionJuego &juego, EstadisticasTurno &estadisticas){
    /*
     * Presenta las estadisticas del ultimo turno
     */
    imprimirCantidades(estadisticas);
    actualizarValores(juego, estadisticas);
    imprimirPromedios(juego);
}

char imprimirNuevoTurno(char eleccionPasada, InformacionJuego &juego, EstadisticasTurno &estadisticas){

    if(eleccionPasada == '1' || eleccionPasada == '2') {
        imprimirGrilla(juego.grillaJuego.grilla);
        presentarEstadisticas(juego, estadisticas);
    }
    char eleccionMenu = imprimirMenuJuego();

    return eleccionMenu;
}

void jugar(InformacionJuego &juego, EstadisticasTurno estadisticas){
    /*
     * Se encarga de correr el juego
     */
    char eleccionMenu; //Lo uso para determinar la eleccion del menu
    imprimirInicial(estadisticas, juego);
    do{
        eleccionMenu = imprimirNuevoTurno(eleccionMenu, juego, estadisticas);
        switch(eleccionMenu){
            case '1':
                actualizarGrilla(juego.grillaJuego, estadisticas);
                break;
            case '2':
                reiniciarJuego(juego.grillaJuego, estadisticas);
                break;
            case '3':
                break;
            default: imprimirEleccionErronea(eleccionMenu);
        }
    }while(eleccionMenu != '3');
}

void reiniciarJuego(Tablero &grillas, EstadisticasTurno &estadisticas){
    /*
     * Reinicia el juego copiando la grilla inicial
     * en la grilla
     */
    setearEstadisticasCero(estadisticas);
     for(int fila = 0; fila < 20; fila++){
         for(int columna = 0; columna < 80; columna++){
             grillas.grilla[fila][columna] = grillas.grillaInicial[fila][columna];
             if(grillas.grillaInicial[fila][columna]){
                 estadisticas.cantidadVivas++;
             }//Fin if
         }//Fin for interno
     }//Fin for externo

}
