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
                cout << "+";
            }//Fin if
            else {
                cout << "*";
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
