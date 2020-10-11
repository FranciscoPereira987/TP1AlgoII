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
    }; //Son las posiciones relativas de las celulas adyacentes
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
void contarCelulas(EstadisticasTurno &estadisticas, bool nuevoEstado, bool estadoPasado){
    /*
     * Cuenta si una celula nacio o murio
     */
    if(nuevoEstado && !estadoPasado){//Si esta viva y antes estaba muerta
        estadisticas.cantidadNacimientos += 1;
        estadisticas.cantidadVivas += 1;
    }//Fin if
    else if (!nuevoEstado && estadoPasado){//Si esta muerta y estaba viva
        estadisticas.cantidadMuertes += 1;
        estadisticas.cantidadVivas -= 1;
    }//Fin else if
}
bool determinarCaso(bool estadoPasado, char vivasAdyacentes, EstadisticasTurno &estadisticas){
    /*
     * define un numero de acuerdo al estado de la celula y
     * de la cantidad de vivas adyacentes en el turno pasado
     */
    bool viva;

    if(estadoPasado){
        viva = (vivasAdyacentes == 3) || (vivasAdyacentes == 2);
    }//Fin if
    else{
        viva = (vivasAdyacentes == 3);
    }//Fin else

    contarCelulas(estadisticas, viva, estadoPasado);

    return viva;
}
void cargarProximoTurno(Tablero &grilla, char grillaNumerica[20][80], EstadisticasTurno &estadisticas){
    /*
     * Modifica la grilla segun la cantidad de vivas
     * adyacentes
     */
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            grilla.grilla[fila][columna] = determinarCaso(
                    grilla.grilla[fila][columna],
                    grillaNumerica[fila][columna],
                    estadisticas
                    );
        }//Fin for interno
    }//Fin for externo
}
void actualizarGrilla(Tablero &grilla, EstadisticasTurno &estadisticas){
    /*
     * Se encarga de actualizar el tablero
     * luego de cada turno
     */
    char grillaNumerica[20][80];
    cargarCerosGrilla(grillaNumerica);
    rellenarGrillaNumerica(grilla.grilla, grillaNumerica);
    cargarProximoTurno(grilla, grillaNumerica, estadisticas);
}

int calcularPromedio(int suma, int cantidadTurnos){
    //Calcula promedio de muertes y nacimientos

    return (suma / cantidadTurnos); // Es siempre una division entera
}

void actualizarValores(InformacionJuego &juego, EstadisticasTurno &estadisticas){
    /*
     * Actualiza los valores de sumas, cant turno, cant Muertes y demas
     */
    juego.cantTurnos++;
    juego.totalNacimientos += estadisticas.cantidadNacimientos;
    juego.totalMuertes += estadisticas.cantidadMuertes;

    estadisticas.cantidadNacimientos = 0;
    estadisticas.cantidadMuertes = 0;
}

int evaluarCambios(EstadisticasTurno estadisticas){
    /*
     * Evalua la cantidad de cambios que ocurrieron en un turno
     */
    int cantCambios = estadisticas.cantidadNacimientos + estadisticas.cantidadMuertes;
    //Los cambios equivalen a la cantidad de celulas que murieron mas las que nacieron
    return cantCambios;
}

bool evaluarEstabilidad(EstadisticasTurno &estadisticas){
    int cambiosTurno = evaluarCambios(estadisticas);
    bool estable = (cambiosTurno == 0 && estadisticas.cantidadCambios == 0);
    estadisticas.cantidadCambios = cambiosTurno; //Guardo la cantidad de cambios para evaluarla a futuro

    return estable;
}
