//
// Created by francisco on 10/10/20.
//

#ifndef TP1ALGOII_ARITMETICA_H
#define TP1ALGOII_ARITMETICA_H

void actualizarGrilla(Tablero &grilla, EstadisticasTurno &estadisticasTurno);
bool controlarPosicion(int filaActual, int colunmaActual);
void actualizarValores(InformacionJuego &juego, EstadisticasTurno &estadisticas);

int calcularPromedio(int suma, int cantidad);

#endif //TP1ALGOII_ARITMETICA_H
