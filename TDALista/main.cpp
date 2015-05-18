#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "linkedlist.h"
#include "fscursorlist.h"
#include "fsarraylist.h"
#include "integer.h"
#include <time.h>
#include <ctime>

using namespace std;

/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
*  - Inserción
*  - Eliminación
*  - Listado
*  - Búsqueda
*/


int menu();

int main(int argc, char *argv[])
{
    // En el caso de que quisieramos utilizar otra implementación
    // SÓLO se tendría que cambiar esta línea.
    TDAList* listaLinked;
    TDAList* listaArray;
    TDAList* listaCursor;
    Integer* intTemp;
    int val, pos;
    bool flag = true;
    while (flag)
    {
        switch(menu())
        {
           case 1:           
              
              /*for (int i = 1; i < 1000; ++i){
                listaLinked = new LinkedList(i);

                clock_t empiezaLinked = clock();
                for (int j = 0; j < i; ++j){
                  listaLinked->insert(0,j);
                }
                clock_t finalLinked = clock();
                double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                cout << secLinked << endl;
                delete listaLinked;
              }
              cout << "***********************************************************" << endl;*/
              for (int i = 0; i < 1000; ++i){
                listaArray = new FSArrayList(i);

                clock_t empiezaArray = clock();
                for (int j = 0; j < i; ++j){
                  listaArray->insert(0,j);
                }
                clock_t finalArray = clock();
                double secArray = double(finalArray - empiezaArray) / CLOCKS_PER_SEC;
                cout << secArray << endl;
                delete listaArray;
              }
              cout << "***********************************************************" << endl;
              /*for (int i = 0; i < 1000; ++i){
                listaCursor = new FSCursor(i);

                clock_t empiezaCursor = clock();
                for (int j = 0; j < i; ++j){
                  listaCursor->insert(0,j);
                }
                clock_t finalCursor = clock();
                double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                cout << secCursor << endl;
                delete listaCursor;
              }*/
           /*case 2:
               for (int i = 1; i < 1000; ++i){
                listaLinked = new LinkedList(i);

                clock_t empiezaLinked = clock();
                for (int j = 0; j < i; ++j){
                  listaLinked->erase(0,j);
                }
                clock_t finalLinked = clock();
                double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                cout << secLinked << endl;
                delete listaLinked;
              }
              cout << "***********************************************************" << endl;
              for (int i = 0; i < 1000; ++i){
                listaArray = new FSArrayList(i);

                clock_t empiezaArray = clock();
                for (int j = 0; j < i; ++j){
                  listaArray->insert(0,j);
                }
                clock_t finalArray = clock();
                double secArray = double(finalArray - empiezaArray) / CLOCKS_PER_SEC;
                cout << secArray << endl;
                delete listaArray;
              }
              cout << "***********************************************************" << endl;
              for (int i = 0; i < 1000; ++i){
                listaCursor = new FSCursor(i);

                clock_t empiezaCursor = clock();
                for (int j = 0; j < i; ++j){
                  listaCursor->insert(0,j);
                }
                clock_t finalCursor = clock();
                double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                cout << secCursor << endl;
                delete listaCursor;
              }
           case 3:
               lista->print();
               break;
           case 4:
               cout << "Valor del Elemento a Buscar: ";
               cin >> val;
               intTemp = new Integer(val);
               pos = lista->indexOf(intTemp);
               delete intTemp;
               cout << "El Elemento esta en la posicion = " << pos << endl;
               break;
           case 9:
               flag = false;*/
        }
    }
    //delete lista;

    return 0;
}
int menu()
{
    cout << "1. Insertar "  << endl;
    cout << "2. Borrar "  << endl;
    cout << "3. Listar " << endl;
    cout << "4. Buscar " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}
