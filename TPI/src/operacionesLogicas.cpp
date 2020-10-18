/*
 * Contiene funciones que se encargan de contar celulas de
 * la grilla
 *
 */
#include "estructuras.h"
/*
* Pone todos los valores de una grilla numerica en cero
*/
void cargarCerosGrilla(char grillaNumerica[20][80]){

    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            grillaNumerica[fila][columna] = 0;
        }
    }
}
/*
* Controla que los paramentros pasados se encuentren dentro de la grilla
*
*/
bool controlarPosicion(int filaActual, int colunmaActual){

	/*Defino las dos variables, si esta dentro de los rangos de fila y columna
	 */
    bool filaEnOrden = (filaActual >= 0) && (filaActual <= 19),

    columnaEnOrden = (colunmaActual >= 0) && (colunmaActual <= 79);
    /*Devuelvo la conjucion de ambos*/
    return filaEnOrden && columnaEnOrden;
}
/*
* Actualiza el numero de celulas vivas adyacentes
* a una celda que contiene una celula viva
*/
void actualizarAdyacentes(char grillaNumerica[20][80], int fila, int columna){

    int filaActual, columnaActual;

    /*Son las posiciones relativas de las celulas adyacentes*/
    int movimientos[][2] = {
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
            {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };
    for(int i = 0; i < 8; i++){
        filaActual = movimientos[i][0] + fila;
        columnaActual = movimientos[i][1] + columna;
        /*Solamente actualizo el valor de la celda si la celda esta en la grilla*/
        if(controlarPosicion(filaActual, columnaActual)) {
            grillaNumerica[filaActual][columnaActual] += 1;
        }
    }

}
/*
* Carga los valores correspondientes a vivas adyacentes en la
* grilla numerica
*/
void rellenarGrillaNumerica(bool grilla[20][80], char grillaNumerica[20][80]){

    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            if(grilla[fila][columna]){
                actualizarAdyacentes(grillaNumerica, fila, columna);
            }
        }
    }
}
/*
* Cuenta si una celula nacio o murio
*/
void contarCelulas(EstadisticasTurno &estadisticas, bool nuevoEstado, bool estadoPasado){

	/*Si esta viva y antes estaba muerta*/
    if(nuevoEstado && !estadoPasado){
    	/*Nacio la celula y hay una viva mas*/
        estadisticas.cantidadNacimientos += 1;
        estadisticas.cantidadVivas += 1;
    }
    /*Si esta muerta y estaba viva*/
    else if (!nuevoEstado && estadoPasado){
    	/*Se murio y Hay una viva menos*/
        estadisticas.cantidadMuertes += 1;
        estadisticas.cantidadVivas -= 1;
    }
}

/*
* Devuelve true o false, dependiendo de si la celula debe nacer, morir, seguir viva
* o seguir muerta
*/
bool determinarCaso(bool estadoPasado, char vivasAdyacentes, EstadisticasTurno &estadisticas){

    bool viva;

    if(estadoPasado){
        viva = (vivasAdyacentes == 3) || (vivasAdyacentes == 2);
    }
    else{
        viva = (vivasAdyacentes == 3);
    }

    contarCelulas(estadisticas, viva, estadoPasado);

    return viva;
}

/*
* Modifica la grilla segun la cantidad de vivas
* adyacentes
*/
void cargarProximoTurno(Tablero &grilla, char grillaNumerica[20][80], EstadisticasTurno &estadisticas){

    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
        	/*Le asigno como nuevo valor el booleano devuelto por esta funcion*/
            grilla.grilla[fila][columna] = determinarCaso(
                    /*El estado pasado de la celula*/
            		grilla.grilla[fila][columna],
                    /*La cantidad de vivas adyacentes*/
					grillaNumerica[fila][columna],
                    estadisticas
                    );
        }
    }
}

/*
* Se encarga de actualizar el tablero
* luego de cada turno
*/
void actualizarGrilla(Tablero &grilla, EstadisticasTurno &estadisticas){

    char grillaNumerica[20][80];

    /*Genero la grilla numerica*/
    cargarCerosGrilla(grillaNumerica);
    rellenarGrillaNumerica(grilla.grilla, grillaNumerica);
    /*Actualizo la grilla con las celulas*/
    cargarProximoTurno(grilla, grillaNumerica, estadisticas);
}

/*
* Calcula promedio de muertes y nacimientos.
*/
int calcularPromedio(int suma, int cantidadTurnos){

	/*Es siempre una division entera*/
    return (suma / cantidadTurnos);
}

/*
* Actualiza los valores de sumas, cant turno, cant Muertes y demas
*/
void actualizarValores(InformacionJuego &juego, EstadisticasTurno &estadisticas){

    juego.cantTurnos++;
    /*Agrego las muertes y nacimientos del turno pasado*/
    juego.totalNacimientos += estadisticas.cantidadNacimientos;
    juego.totalMuertes += estadisticas.cantidadMuertes;

    /*Devuelvo la cantidad de muertes y nacimientos a cero*/
    estadisticas.cantidadNacimientos = 0;
    estadisticas.cantidadMuertes = 0;
}


/*
* Evalua la cantidad de cambios que ocurrieron en un turno
*/
int evaluarCambios(EstadisticasTurno estadisticas){
	/*Los cambios equivalen a la cantidad de celulas que murieron mas las que nacieron*/
    int cantCambios = estadisticas.cantidadNacimientos + estadisticas.cantidadMuertes;

    return cantCambios;
}


/*
* Devuelve true, si los cambios en el turno actual y el pasado equivalen a cero
*/
bool evaluarEstabilidad(EstadisticasTurno &estadisticas){

    int cambiosTurno = evaluarCambios(estadisticas);
    bool estable = (cambiosTurno == 0 && estadisticas.cantidadCambios == 0);
    /*Guardo la cantidad de cambios para evaluarla a futuro*/
    estadisticas.cantidadCambios = cambiosTurno;

    return estable;
}
