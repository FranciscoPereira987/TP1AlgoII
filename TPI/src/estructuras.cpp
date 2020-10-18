/*
 * Modulo que contiene funciones de las estructuras
 * definidas en el header correspondiente
 */

#include "estructuras.h"
//Funciones de inicializacion de estructuras


/*
* Inicializa la grilla con
* todos valores en false
*/
Tablero inicializarGrilla(){

    Tablero tablero;
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            tablero.grillaInicial[fila][columna] = false;
            tablero.grilla[fila][columna] = false;
        }//Fin for interno
    }//Fin for

    return tablero;
}
/*
* Inicializa la estructura principal del juego
*
*/
InformacionJuego iniciarJuego(){

    InformacionJuego juegoNuevo;

    juegoNuevo.grillaJuego = inicializarGrilla();
    juegoNuevo.totalNacimientos = 0;
    juegoNuevo.totalMuertes = 0;
    juegoNuevo.cantTurnos = 0;//Considera al primer turno como
    //la primer evolucion luego de haber colocado los valores

    return juegoNuevo;
}

/*
* Devuelve todos los valores de una estadistica de juego
* a cero
*/
void setearEstadisticasCero(EstadisticasTurno& estadisticas){

    estadisticas.cantidadVivas = 0;
    estadisticas.cantidadMuertes = 0;
    estadisticas.cantidadNacimientos = 0;
    estadisticas.cantidadCambios = 0;
}
