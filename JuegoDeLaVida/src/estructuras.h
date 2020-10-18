//
// Created by francisco on 10/10/20.
//
#ifndef TP1ALGOII_ESTRUCTURAS_H
#define TP1ALGOII_ESTRUCTURAS_H

/*
 * Contiene a la grilla y una grilla
 * inicial
 */

struct Tablero{

    bool grilla[20][80];

    bool grillaInicial[20][80];
};

/*
 * Contiene a la grilla e informacion
 * general sobre el juego
 */
struct InformacionJuego{

    Tablero grillaJuego;


    unsigned int totalMuertes;
    unsigned int totalNacimientos;
    unsigned int cantTurnos;
};

/*
 * Guarda las estadisticas
 * de un turno en particular
 */
struct EstadisticasTurno{


    unsigned int cantidadVivas;
    unsigned int cantidadMuertes;
    unsigned int cantidadNacimientos;
    unsigned int cantidadCambios;

};

InformacionJuego iniciarJuego();
void setearEstadisticasCero(EstadisticasTurno &estadisticas);


#endif //TP1ALGOII_ESTRUCTURAS_H
