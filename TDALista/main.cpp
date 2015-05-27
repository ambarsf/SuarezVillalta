#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "linkedlist.h"
#include "fscursorlist.h"
#include "fsarraylist.h"
#include "integer.h"
#include <stdlib.h> 
#include <time.h>
#include <ctime>
using namespace std;
/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
* - Inserción
* - Eliminación
* - Listado
* - Búsqueda
*/

int menu();
void imprimir(double[1000][6]);
void imprimirDoble(double [1000][4]);

int main(int argc, char *argv[]){
// En el caso de que quisieramos utilizar otra implementación
// SÓLO se tendría que cambiar esta línea.
TDAList* lista;
 
Integer* intTemp;
int val, pos;
bool flag = true;
int x = 0, y = 0;
int p = 0;
	while (flag){
		int x = 0, y = 0;
		int p = 0;
		switch(menu()){
			case 1:{
				double resultados[1000][6];
				for (int i = 1; i <= 1000; ++i){ //Insert
					lista = new FSArrayList(i);	// ********   Para probar otro tipo solo cambiar esta linea    ********
					clock_t empiezaInsert = clock();
					y = 0;
					for (int j = 0; j < i; ++j){
						lista->insert(new Integer(0), p);
						p = rand() % lista->getSize();
					}
					clock_t finalInsert = clock();
					double tiempoInsert = double(finalInsert - empiezaInsert) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoInsert;

					clock_t empiezaGet = clock();
					y = 2;
					for (int j = 0; j < i; ++j){ // Get
						p = rand() % lista->getSize();
						lista->get(p);
					}
					clock_t finalGet = clock();
					double tiempoGet = double(finalGet - empiezaGet) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoGet;

					clock_t empiezaIndexOf = clock();
					y = 3;
					for (int j = 0; j < i; ++j){ // IndexOf
						p = rand() % lista->getSize();
						lista->indexOf(lista->get(p));
					}
					clock_t finalIndexOf = clock();
					double tiempoIndexOf = double(finalIndexOf - empiezaIndexOf) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoIndexOf;

					clock_t empiezaFirst = clock();
					y = 4;
					for (int j = 0; j < i; ++j){ // First
						p = rand() % lista->getSize();
						lista->first();
					}
					clock_t finalFirst = clock();
					double tiempoFirst = double(finalFirst - empiezaFirst) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoFirst;

					clock_t empiezaLast = clock();
					y = 5;
					for (int j = 0; j < i; ++j){ // Last
						p = rand() % lista->getSize();
						lista->first();
					}
					clock_t finalLast = clock();
					double tiempoLast = double(finalLast - empiezaLast) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoLast;

					clock_t empiezaRemove = clock();
					y = 1;
					for (int j = 0; j < i; ++j){ // Remove
						p = rand() % lista->getSize();
						lista->erase(p);
					}
					clock_t finalRemove = clock();
					double tiempoRemove = double(finalRemove - empiezaRemove) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoRemove;

					x++;
					delete lista;
				}
				imprimir(resultados);
			}
			break;
			case 2:{
				double resultados[1000][4];
				for (int i = 1; i <= 1000; ++i){ //Insert
					lista = new FSCursor(i);	// ********   Para probar otro tipo solo cambiar esta linea    ********
					for (int j = 0; j < i; ++j){
						lista->insert(new Integer(0), p);
						cout << "Size  Insertar" << lista->getSize() << endl;
						p = rand() % lista->getSize();
					}
					cout << "Paso Insert" << endl;

					clock_t empiezaGet = clock();
					y = 0;
					for (int j = 0; j < i; ++j){ // Get
						cout << "Size  " << lista->getSize() << endl;
						p = rand() % lista->getSize();
						lista->get(p);
					}
					clock_t finalGet = clock();
					double tiempoGet = double(finalGet - empiezaGet) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoGet;
					cout << "Paso Get" << endl;

					clock_t empiezaIndexOf = clock();
					y = 1;
					for (int j = 0; j < i; ++j){ // IndexOf
						p = rand() % lista->getSize();
						lista->indexOf(lista->get(p));
					}
					clock_t finalIndexOf = clock();
					double tiempoIndexOf = double(finalIndexOf - empiezaIndexOf) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoIndexOf;
					cout << "Paso IndexOf" << endl;

					clock_t empiezaFirst = clock();
					y = 2;
					for (int j = 0; j < i; ++j){ // First
						p = rand() % lista->getSize();
						lista->first();
					}
					clock_t finalFirst = clock();
					double tiempoFirst = double(finalFirst - empiezaFirst) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoFirst;
					cout << "Paso First" << endl;

					clock_t empiezaLast = clock();
					y = 3;
					for (int j = 0; j < i; ++j){ // Last
						p = rand() % lista->getSize();
						lista->first();
					}
					clock_t finalLast = clock();
					double tiempoLast = double(finalLast - empiezaLast) / CLOCKS_PER_SEC;
					resultados[x][y] = tiempoLast;
					cout << "Paso Last" << endl;

					x++;
					delete lista;
				}
				imprimirDoble(resultados);
			}
			break;
			case 3:{
				lista->print();
			}
			break;
			case 4:{
				cout << "Valor del Elemento a Buscar: ";
				cin >> val;
				intTemp = new Integer(val);
				pos = lista->indexOf(intTemp);
				delete intTemp;
				cout << "El Elemento esta en la posicion = " << pos << endl;
			}
			break;
			case 9:
				flag = false;
		}
	}
	return 0;
}
int menu(){
	cout << "1. Insertar, Eliminar, Get, IndexOf, First y Last" << endl;
	cout << "2. Get, IndexOf, First y Last (No Funka)" << endl;
	cout << "9. Salir " << endl;
	cout << endl << "Opcion? ";
	int opcion;
	cin >> opcion;
return opcion;
}

void imprimir(double resultados[1000][6]){
	cout << "Insert\tRemove\tGet\tIndexOf\tFirst\tLast" << endl;
	for (int i = 0; i < 1000; ++i){
		for (int j = 0; j < 6; ++j){
			cout << resultados[i][j] << "\t";
		}
		cout << endl;
	}
}

void imprimirDoble(double resultados[1000][4]){
	for (int i = 0; i < 1000; ++i){
		for (int j = 0; j < 4; ++j){
			cout << resultados[i][j] << "\t";
		}
		cout << endl;
	}
}