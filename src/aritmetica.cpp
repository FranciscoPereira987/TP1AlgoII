/*
 * Contiene funciones que se encargan de contar celulas de
 * la grilla
 *
 */
#include "estructuras.h"

void cargarCerosGrilla(char grillaNumerica[20][80]){
    /*
     * Pone todos los valores de una grilla numerica en cero
     */
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            grillaNumerica[fila][columna] = 0;
        }//Fin for interno
    }//Fin for
}

bool controlarPosicion(int filaActual, int colunmaActual){
    /*
     * Controla que los paramentros pasados se encuentren dentro de la grilla
     *
     */
    bool filaEnOrden = (filaActual >= 0) && (filaActual <= 19),
    columnaEnOrden = (colunmaActual >= 0) && (colunmaActual <= 79);

    return filaEnOrden && columnaEnOrden;
}

void actualizarAdyacentes(char grillaNumerica[20][80], int fila, int columna){
    /*
     * Actualiza el numero de celulas vivas adyacentes
     * a una celda que contiene una celula viva
     */
    int filaActual, columnaActual;

    int movimientos[][2] = {
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
            {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };
    for(int i = 0; i < 8; i++){
        filaActual = movimientos[i][0] + fila;
        columnaActual = movimientos[i][1] + columna;
        if(controlarPosicion(filaActual, columnaActual)) {
            //Solamente actualizo el valor de la celda si la celda
            //esta en la grilla
            grillaNumerica[filaActual][columnaActual] += 1;
        }//Fin if
    }//FIn cilo for
}

void rellenarGrillaNumerica(bool grilla[20][80], char grillaNumerica[20][80]){

    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            if(grilla[fila][columna]){
                actualizarAdyacentes(grillaNumerica, fila, columna);
            }//Fin if
        }//Fin for interno
    }//Fin for externo
}

bool determinarCaso(bool estadoPasado, char vivasAdyacentes){
    /*
     * define un numero de acuerdo al estado de la celula y
     * de la cantidad de vivas adyacentes en el turno pasado
     */
    bool viva;
    switch(estadoPasado){
        case true:
            viva = (vivasAdyacentes == 3) || (vivasAdyacentes == 2); break;
        case false:
            viva = (vivasAdyacentes == 3);
    }

    return viva;
}

void cargarProximoTurno(Tablero &grilla, char grillaNumerica[20][80]){
    /*
     * Modifica la grilla segun la cantidad de vivas
     * adyacentes
     */
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            grilla.grilla[fila][columna] = determinarCaso(
                    grilla.grilla[fila][columna],
                    grillaNumerica[fila][columna]
                    );
        }//Fin for interno
    }//Fin for externo
}

void actualizarGrilla(Tablero &grilla){
    /*
     * Se encarga de actualizar el tablero
     * luego de cada turno
     */
    char grillaNumerica[20][80];
    cargarCerosGrilla(grillaNumerica);
    rellenarGrillaNumerica(grilla.grilla, grillaNumerica);
    cargarProximoTurno(grilla, grillaNumerica);
}
