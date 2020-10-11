//
// Created by francisco on 10/10/20.
//

#ifndef TP1ALGOII_IMPRESIONES_H
#define TP1ALGOII_IMPRESIONES_H

void imprimirGrilla(bool grilla[20][80]);
void imprimirBienvenida();
char imprimirMenuJuego();
void imprimirEleccionErronea(int opcionElegida);
void imprimirCantidades(EstadisticasTurno estadisticas);
void imprimirPromedios(InformacionJuego juego);
void imprimirInicial(EstadisticasTurno estadisticas, InformacionJuego juego);

int cargarGrilla(Tablero &grilla);

#endif //TP1ALGOII_IMPRESIONES_H
