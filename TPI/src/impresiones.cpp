/*
 * Contiene funciones de impresion para la consola
 * y las funciones que piden ingreso de datos del usuario
 */
#include "estructuras.h"
#include <iostream>

#include "operacionesLogicas.h"
using std::cout;
using std::endl;
using std::cin;

/*
* Imprime la grilla con su estado actual en la pantalla
*/
void imprimirGrilla(bool grilla[20][80]){

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

/*
* Se encarga de imprimir el menu principal
* y de promptear por una respuesta al usuario
*
*/
void imprimirBienvenida(){

    char comenzar;

    cout << "--------------------------"
    	<< endl
    << "JUEGO DE LA VIDA"
		<< endl
    << "--------------------------"
		<< endl << endl
    << "Ingrese cualquier tecla comenzar"
		<< endl
    << ">>>";


    cin >> comenzar; //Espera a que el usuario reaccione

}

void imprimirEleccionErronea(char opcionElegida){
	/*
	 * Informa que se ingreso una opcion invalida
	 * en el menu del juego
	 */
    cout << "La opcion elegida: " << opcionElegida
    	<< endl
	<< "Es incorrecta"
		<< endl;
}


char imprimirMenuJuego(){
    /*
     * Imprime el menu de juego y promptea al
     * usuario por una opcion
     */
    char decision;

    cout << "1- Avanzar turno"
    	<< endl
    << "2- Reiniciar juego"
		<< endl
    << "3- Terminar juego"
		<< endl
    << ">>>";

    cin >> decision;

    return decision;
}

/*
* Define si se siguen o no se siguen cargando los datos
*/
bool continuarCarga(){

    cout << "Ingrese 1 para continuar, cualquier otra tecla para "
    << "terminar la carga de datos:"
		<< endl
	<< ">>>";

    char decision;
    cin >> decision;

    return (decision == '1');
}

/*
* Pregunta fila o columna donde el usuario quiera
* ingresar un dato y lo devuelve.
*/
int preguntarPosicion(char posicion){

    int fila;

    if(posicion == 'f'){
    	cout << "Ingrese la fila de la celula: "
    		<< endl;
    }
    else{
    	cout << "Ingrese la columna de la celula: "
    	    << endl;
    }
	cout << ">>>";

    cin >> fila;
    return fila - 1;
}

/*
* Permite que el usuario carge la cantidad de
* celulas vivas que quiera
*/
int cargarGrilla(Tablero &grilla){

    int contador = 0, fila, columna;
    do{
        fila = preguntarPosicion('f');//Pregunto la posicion de la fila
        columna = preguntarPosicion('c');//Pregunto la posicion de la columna

        if(controlarPosicion(fila, columna)) {
        	//Marco la celda ingresada po el usuario como viva
            grilla.grillaInicial[fila][columna] = grilla.grilla[fila][columna] = true;


            contador++;//Sumo el contador de vivas
        }//Fin del if
        else{
            cout << "La posicion ingresada no existe"
            	<< endl;
        }
    }while(continuarCarga());

    return contador;
}

/*
 * Informa la cantidad de vivas en el juego
*/
void imprimirVivas( int cantVivas){

    cout << "Cantidad celulas vivas: " << cantVivas;
}

/*
* Imprime el estado inicial de la grilla junto con la cantidad
* inicial de celulas vivas
*/
void imprimirInicial(EstadisticasTurno estadisticas, InformacionJuego juego){

    imprimirGrilla(juego.grillaJuego.grillaInicial);//Imprimo el estado inicial de la grilla
    imprimirVivas(estadisticas.cantidadVivas);//Informo la cantidad de celulas vivas

    cout << endl;
}

/*
 * Imprime las estadisticas de un turno
 */
void imprimirCantidades(EstadisticasTurno estadisticas){

    imprimirVivas(estadisticas.cantidadVivas);
    cout << " -- " << "Cantidad de muertes: " << estadisticas.cantidadMuertes
    << " -- " << "Cantidad de nacimientos: " << estadisticas.cantidadNacimientos
    << endl;
}

/*
 * Imprime los promedios de muerte y nacimientos historicos
 */
void imprimirPromedios(InformacionJuego juego){

    cout << "Promedio de muertes: " << calcularPromedio(juego.totalMuertes, juego.cantTurnos)
    << " -- " << "Promedio de nacimientos: " << calcularPromedio(juego.totalNacimientos, juego.cantTurnos)
    << endl;
}

/*
 * Le informa al usuario que no hubo cambios en dos o mas turnos
 */
void imprimirEstabilidad(EstadisticasTurno &estadisticas){

    if(evaluarEstabilidad(estadisticas)) {
        cout << ">>>No hubo cambios por 2 o mas turnos<<<" << endl;
    }//Fin if
}
