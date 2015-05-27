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
void imprimir(double[1000][2]);

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
	switch(menu()){
		case 1:{
			double resultados[1000][2];
			for (int i = 1; i <= 1000; ++i){ //Insert
				lista = new FSCursor(i);	// ********   Para probar otro tipo solo cambiar esta linea    ********
				clock_t empiezaInsert = clock();
				y = 0;
				for (int j = 0; j < i; ++j){
					if (lista->insert(new Integer(0), p) ) //;
						cout << lista->getSize() << endl;
					//if (i == 3){ // LinkedList
					//	cout << "Este es el objeto" << endl; // LinkedList
					//	lista->get(0)->print() ; // LinkedList
					//	cout << endl << "Tamano" << lista->getSize() << endl; // LinkedList
					//}
					p = rand() % lista->getSize();
				}
				clock_t finalInsert = clock();
				double tiempoInsert = double(finalInsert - empiezaInsert) / CLOCKS_PER_SEC;
				resultados[x][y] = tiempoInsert;

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
			for (int i = 1; i < 1000; ++i){
				lista = new LinkedList(i);
				for (int j = 0; j < i; ++j){
					lista->insert(0,j);
				}
				clock_t empiezaLinked = clock();
				for (int j = 0; j < i; ++j){
					lista->erase(j);
				}
				clock_t finalLinked = clock();
				double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
				cout << secLinked << endl;
				delete lista;
			}
			
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
//delete lista;
return 0;
}
int menu(){
	cout << "1. Insertar " << endl;
	cout << "2. Borrar " << endl;
	cout << "3. Listar " << endl;
	cout << "4. Buscar " << endl;
	cout << "9. Salir " << endl;
	cout << endl << "Opcion? ";
	int opcion;
	cin >> opcion;
return opcion;
}

void imprimir(double resultados[1000][2]){
	for (int i = 0; i < 1000; ++i){
		for (int j = 0; j < 2; ++j){
			cout << resultados[i][j] << "\t";
		}
		cout << endl;
	}
}