/*
 * Contiene funciones de impresion para la consola
 * y las funciones que piden ingreso de datos del usuario
 */
#include "estructuras.h"
#include "aritmetica.h"


#include <iostream>
using std::cout;
using std::endl;
using std::cin;


void imprimirGrilla(bool grilla[20][80]){
    /*
     * Imprime la grilla con su estado actual en la pantalla
     */
    for(int fila = 0; fila < 20; fila++){
        for(int columna = 0; columna < 80; columna++){
            if(grilla[fila][columna]){
                cout << "*";
            }//Fin if
            else {
                cout << ".";
            }//Fin else
        }//Fin for interno
        cout << endl;
    }//Fin for externo
}//Fin funcion


void imprimirBienvenida(){
    /*
     * Se encarga de imprimir el menu principal
     * y de promptear por una respuesta al usuario
     *
     */
    char comenzar;

    cout << "--------------------------" << endl
    << "JUEGO DE LA VIDA" << endl
    << "--------------------------" << endl << endl
    << "Ingrese cualquier tecla comenzar" << endl
    << ">>>";

    cin >> comenzar;
}

void imprimirEleccionErronea(int opcionElegida){

    cout << "La opcion elegida: " << opcionElegida
    << endl << "es incorrecta" << endl;
}


char imprimirMenuJuego(){
    /*
     * Imprime el menu de juego y promptea al
     * usuario por una opcion
     */
    char decision;

    cout << "1- Avanzar turno" << endl
    << "2- Reiniciar juego" << endl
    << "3- Terminar juego" << endl
    << ">>>";

    cin >> decision;

    return decision;
}

bool continuarCarga(){
    /*
     * Define si se siguen o no se siguen cargando los datos
     */
    cout << "Ingrese 1 para continuar, cualquier otra tecla para "
    << "terminar la carga de datos:" << endl << ">>";

    char decision;
    cin >> decision;

    return (decision == '1');
}

int preguntarFila(){
    /*
     * Pregunta en que fila quiere cargar una celula viva
     */
    int fila;
    cout << "Ingrese la fila de la celula: "
    << endl << ">>>";

    cin >> fila;
    return fila - 1;
}

int preguntarColummna(){
    /*
     * Pregunta en que columna quiere cargar la celula
     */
    int columna;
    cout << "Ingrese la columna de la celula: "
    << endl << ">>>";

    cin >> columna;
    return columna - 1;
}


int cargarGrilla(Tablero &grilla){
    /*
     * Permite que el usuario carge la cantidad de
     * celulas vivas que quiera
     */
    int contador = 0, fila, columna;
    do{
        fila = preguntarFila();
        columna = preguntarColummna();
        if(controlarPosicion(fila, columna)) {
            grilla.grillaInicial[fila][columna] = true;
            grilla.grilla[fila][columna] = true;
            contador++;
        }//Fin del if
        else{
            cout << "La posicion ingresada no existe" << endl;
        }
    }while(continuarCarga());

    return contador;
}

void imprimirVivas( int cantVivas){

    cout << "Cantidad celulas vivas: " << cantVivas;
}

void imprimirInicial(EstadisticasTurno estadisticas, InformacionJuego juego){

    imprimirGrilla(juego.grillaJuego.grillaInicial);
    imprimirVivas(estadisticas.cantidadVivas);
    cout << endl;
}

void imprimirCantidades(EstadisticasTurno estadisticas){
    /*
     * Imprime las estadisticas de un turno
     */
    imprimirVivas(estadisticas.cantidadVivas);
    cout << " -- " << "Cantidad de muertes: " << estadisticas.cantidadMuertes
    << " -- " << "Cantidad de nacimientos: " << estadisticas.cantidadNacimientos
    << endl;
}

void imprimirPromedios(InformacionJuego juego){

    cout << "Promedio de muertes: " << calcularPromedio(juego.totalMuertes, juego.cantTurnos)
    << " -- " << "Promedio de nacimientos: " << calcularPromedio(juego.totalNacimientos, juego.cantTurnos)
    << endl;
}