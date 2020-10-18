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
    estadisticas.cantidadVivas = cargarGrilla(grillaJuego); // Cargo la grilla

    return estadisticas;
}

/*
 * Presenta las estadisticas del ultimo turno
 */
void presentarEstadisticas(InformacionJuego &juego, EstadisticasTurno &estadisticas){

    imprimirCantidades(estadisticas);// De muertes, nacimientos y vivas
    actualizarValores(juego, estadisticas);//Suma las muertes y los nacimientos al total
    imprimirPromedios(juego);//Imprime los promedios de muertes y nacimientos historicos
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
             }//Fin if
         }//Fin for interno
     }//Fin for externo

}

/*
 * Se encarga de correr el juego
 */
void jugar(InformacionJuego &juego, EstadisticasTurno &estadisticas){

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


/*
 * Integra todo el programa
*/
void juegoDeLaVida(){

    InformacionJuego juegoActual = iniciarJuego();
    EstadisticasTurno estadisticas = presentarJuego(juegoActual.grillaJuego);
    jugar(juegoActual, estadisticas);
}

