//
// Created by francisco on 10/10/20.
//
#include "estructuras.h"
#include "impresiones.h"
#include "aritmetica.h"

#include <iostream>

void reiniciarJuego(Tablero &grillas, EstadisticasTurno &estadisticas);
EstadisticasTurno presentarJuego(Tablero &grilla);
void jugar(InformacionJuego &juego, EstadisticasTurno &estadisticas);

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
    imprimirCantidades(estadisticas);// De muertes, nacimientos y vivas
    actualizarValores(juego, estadisticas);//Suma las muertes y los nacimientos al total
    imprimirPromedios(juego);//Imprime los promedios de muertes y nacimientos historicos
}

char imprimirNuevoTurno(char eleccionPasada, InformacionJuego &juego, EstadisticasTurno &estadisticas){
	/*
	 * Imprime la grilla despues de haber avanzado en un turno o
	 * reiniciado el juego
	 */
    if(eleccionPasada == '1' || eleccionPasada == '2') {
        imprimirGrilla(juego.grillaJuego.grilla);
        presentarEstadisticas(juego, estadisticas);
    }
    char eleccionMenu = imprimirMenuJuego();

    return eleccionMenu;
}

void jugar(InformacionJuego &juego, EstadisticasTurno &estadisticas){
    /*
     * Se encarga de correr el juego
     */
    char eleccionMenu; //Lo uso para determinar la eleccion del menu

    imprimirInicial(estadisticas, juego);//Imprimo el estado inicial
    do{
        eleccionMenu = imprimirNuevoTurno(eleccionMenu, juego, estadisticas);//Imprimo y pido una opcion
        switch(eleccionMenu){
            case '1'://Avanzo el turno al siguiente
                actualizarGrilla(juego.grillaJuego, estadisticas);
                imprimirEstabilidad(estadisticas);
                break;
            case '2'://reinicio el juego
                reiniciarJuego(juego.grillaJuego, estadisticas);
                break;
            case '3'://Me salgo del while, termina el programa
                break;
            default: imprimirEleccionErronea(eleccionMenu);//Imprimo un mensaje de error
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
