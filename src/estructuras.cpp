/*
 * Modulo que contiene las estructuras
 * y sus metodos de inicializacion
 */

struct Tablero{

    bool grilla[20][80];

    bool grillaInicial[20][80];

};

struct InformacionJuego{

    Tablero grillaJuego;


    unsigned int totalMuertes;
    unsigned int totalNacimientos;
    unsigned int cantTurnos; //Considera al primer turno como
    //la primer evolucion luego de haber colocado los valores
};

struct EstadisticasTurno{
    // Guarda las estadisticas
    // de un turno en particular

    unsigned int cantidadVivas;
    unsigned int cantidadMuertes;
    unsigned int cantidadNacimientos;

};
//Funciones de inicializacion de estructuras

Tablero inicializarGrilla(){
    /*
     * Inicializa la grilla con
     * todos valores en false
     */
    Tablero tablero;
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            tablero.grillaInicial[fila][columna] = false;
            tablero.grilla[fila][columna] = false;
        }//Fin for interno
    }//Fin for

    return tablero;
}

InformacionJuego iniciarJuego(){
    /*
     * Inicializa la estructura principal del juego
     *
     */
    InformacionJuego juegoNuevo;

    juegoNuevo.grillaJuego = inicializarGrilla();
    juegoNuevo.totalNacimientos = 0;
    juegoNuevo.totalMuertes = 0;
    juegoNuevo.cantTurnos = 0;

    return juegoNuevo;
}

void setearEstadisticasCero(EstadisticasTurno& estadisticas){
    /*
     * Devuelve todos los valores de una estadistica de juego
     * a cero
     */
    estadisticas.cantidadVivas = 0;
    estadisticas.cantidadMuertes = 0;
    estadisticas.cantidadNacimientos = 0;
}