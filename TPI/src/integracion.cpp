//
// Created by francisco on 10/10/20.
//
#include "estructuras.h"
#include "impresiones.h"
#include <iostream>
#include "operacionesLogicas.h"

/*
 * Presenta el juego y carga la grilla
*/
EstadisticasTurno presentarJuego(Tablero &grillaJuego){

    EstadisticasTurno estadisticas;
    imprimirBienvenida();

    setearEstadisticasCero(estadisticas);
    /*Cargo la grilla*/
    estadisticas.cantidadVivas = cargarGrilla(grillaJuego);

    return estadisticas;
}

/*
 * Presenta las estadisticas del ultimo turno
 */
void presentarEstadisticas(InformacionJuego &juego, EstadisticasTurno &estadisticas){

	/*De muertes, nacimientos y vivas*/
    imprimirCantidades(estadisticas);
    /*Suma las muertes y los nacimientos al total*/
    actualizarValores(juego, estadisticas);
    /*Imprime los promedios de muertes y nacimientos historicos*/
    imprimirPromedios(juego);
}

/*
 * Imprime la grilla despues de haber avanzado en un turno o
 * reiniciado el juego
 */
char imprimirNuevoTurno(char eleccionPasada, InformacionJuego &juego, EstadisticasTurno &estadisticas){

    if(eleccionPasada == '1' || eleccionPasada == '2') {
        imprimirGrilla(juego.grillaJuego.grilla);
        presentarEstadisticas(juego, estadisticas);
    }
    char eleccionMenu = imprimirMenuJuego();

    return eleccionMenu;
}

/*
 * Reinicia el juego copiando la grilla inicial
 * en la grilla
 */
void reiniciarJuego(Tablero &grillas, EstadisticasTurno &estadisticas){

    setearEstadisticasCero(estadisticas);
     for(int fila = 0; fila < 20; fila++){
         for(int columna = 0; columna < 80; columna++){
             grillas.grilla[fila][columna] = grillas.grillaInicial[fila][columna];
             if(grillas.grillaInicial[fila][columna]){
                 estadisticas.cantidadVivas++;
             }
         }
     }

}

/*
 * Se encarga de correr el juego
 */
void jugar(InformacionJuego &juego, EstadisticasTurno &estadisticas){

	/*Lo uso para determinar la eleccion del menu*/
    char eleccionMenu;

    /*Imprimo el estado inicial*/
    imprimirInicial(estadisticas, juego);
    do{
    	/*Imprimo y pido una opcion*/
        eleccionMenu = imprimirNuevoTurno(eleccionMenu, juego, estadisticas);
        switch(eleccionMenu){
            /*Avanzo el turno al siguiente*/
            case '1':
                actualizarGrilla(juego.grillaJuego, estadisticas);
                imprimirEstabilidad(estadisticas);
                break;
            /*reinicio el juego*/
            case '2':
                reiniciarJuego(juego.grillaJuego, estadisticas);
                break;
            /*Me salgo del while, termina el programa*/
            case '3':
                break;
            /*Imprimo un mensaje de error*/
            default: imprimirEleccionErronea(eleccionMenu);
        }
    }while(eleccionMenu != '3');
}


/*
 * Integra todo el programa
*/
void juegoDeLaVida(){

    InformacionJuego juegoActual = iniciarJuego();
    EstadisticasTurno estadisticas = presentarJuego(juegoActual.grillaJuego);
    jugar(juegoActual, estadisticas);
}

