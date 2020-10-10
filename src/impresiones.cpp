/*
 * Contiene funciones de impresion para la consola
 * y las funciones que piden ingreso de datos del usuario
 */
#include "estructuras.h"

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
                cout << "V";
            }//Fin if
            else {
                cout << "M";
            }//Fin else
        }//Fin for interno
        cout << endl;
    }//Fin for externo

}//Fin funcion


char imprimirMenuPrincipal(){
    /*
     * Se encarga de imprimir el menu principal
     * y de promptear por una respuesta al usuario
     *
     */
    char decision;

    cout << "--------------------------" << endl
    << "JUEGO DE LA VIDA" << endl
    << "-----------------------" << endl << endl
    << "1- Comenzar" << endl
    << "2- Salir" << endl
    << ">>>";

    cin >> decision;

    return decision;
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

void imprimirEstadisticas(EstadisticasTurno turno){
    /*
     * Imprime las estadisticas del juego
     * luego de cada turno
     */
    cout << "Cantidad celulas vivas: " << turno.cantidadVivas
    << endl
    << "Cantidad nacimientos: " << turno.cantidadNacimientos
    << endl
    << "Cantidad muertes: " << turno.cantidadMuertes
    << endl
    << "Promedio de muertes total: " << turno.promedioMuertes
    << endl
    << "Promedio de nacimientos total: " << turno.promedioNacimientos
    << endl;
}

bool continuarCarga(){
    /*
     * Define si se siguen o no se siguen cargando los datos
     */
    cout << "Ingrese 1 para continuar, cualquier otra tecla para "
    << "terminar la carga de datos:" << endl << ">>";

    int decision;
    cin >> decision;

    return (decision == 1);
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


void cargarGrilla(Tablero &grilla){
    /*
     * Permite que el usuario carge la cantidad de
     * celulas vivas que quiera
     */
    int contador = 0, fila, columna;
    do{
        fila = preguntarFila();
        columna = preguntarColummna();
        grilla.grillaInicial[fila][columna] = true;

    }while(continuarCarga());
}
