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
              
              for (int i = 1; i < 1000; ++i){
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
              cout << "***********************************************************" << endl;
              for (int i = 1; i < 1000; ++i){
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
              for (int i = 1; i < 1000; ++i){
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
              break;
           case 2:
                for (int i = 1; i < 1000; ++i){
                listaLinked = new LinkedList(i);

                for (int j = 0; j < i; ++j){
                  listaLinked->insert(0,j);
                }

                clock_t empiezaLinked = clock();
                for (int j = 0; j < i; ++j){
                  listaLinked->erase(j);
                }
                clock_t finalLinked = clock();
                double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                cout << secLinked << endl;
                //delete listaLinked;
              }
              cout << "***********************************************************" << endl;
              for (int i = 1; i < 1000; ++i){
                listaArray = new FSArrayList(i);

                for (int j = 0; j < i; ++j){
                  listaArray->insert(0,j);
                }

                clock_t empiezaLinked = clock();
                for (int j = 0; j < i; ++j){
                  listaArray->erase(j);
                }
                clock_t finalLinked = clock();
                double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                cout << secLinked << endl;
                delete listaArray;
              }
              cout << "***********************************************************" << endl;
              for (int i = 1; i < 1000; ++i){
                listaCursor = new FSCursor(i);

                for (int j = 0; j < i; ++j){
                  listaCursor->insert(0,j);
                }

                clock_t empiezaCursor = clock();
                for (int j = 0; j < i; ++j){
                  listaCursor->erase(j);
                }
                clock_t finalCursor = clock();
                double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                cout << secCursor << endl;
                //delete listaCursor;
              }
              break;
           case 3:
                for (int i = 1; i < 1000; ++i){
                  listaLinked = new LinkedList(i);

                  for (int j = 0; j < i; ++j){
                    listaLinked->insert(0,j);
                  }

                  clock_t empiezaLinked = clock();
                  listaLinked->first();
                  clock_t finalLinked = clock();
                  double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;

                  cout << secLinked << endl;
                }

                cout << "***********************************************************" << endl;
                for (int i = 1; i < 1000; ++i){
                  listaArray = new FSArrayList(i);
                  for (int j = 0; j < i; ++j){
                    listaArray->insert(0,j);
                  }

                  clock_t empiezaArray = clock();
                  listaArray->first();
                  clock_t finalArray = clock();
                  double secArray = double(finalArray - empiezaArray) / CLOCKS_PER_SEC;
                  cout << secArray << endl;
                }

                  for (int i = 1; i < 1000; ++i){
                    listaCursor = new FSCursor(i);

                    for (int j = 0; j < i; ++j){
                      listaCursor->insert(0,j);
                    }

                    clock_t empiezaCursor = clock();
                    listaCursor->first();
              
                    clock_t finalCursor = clock();
                    double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                    cout << secCursor << endl;
                  }
               break;
           case 4:
               for (int i = 1; i < 1000; ++i){
                  listaLinked = new LinkedList(i);

                  for (int j = 0; j < i; ++j){
                    listaLinked->insert(0,j);
                  }
                  clock_t empiezaLinked = clock();
                  listaLinked->last();
                  clock_t finalLinked = clock();
                  double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;

                  cout << secLinked << endl;
                  delete listaLinked;
                }

                cout << "***********************************************************" << endl;
                for (int i = 1; i < 1000; ++i){
                  listaArray = new FSArrayList(i);
                  for (int j = 0; j < i; ++j){
                    listaArray->insert(0,j);
                  }

                  clock_t empiezaArray = clock();
                  listaArray->last();
                  clock_t finalArray = clock();
                  double secArray = double(finalArray - empiezaArray) / CLOCKS_PER_SEC;
                  cout << secArray << endl;
                  delete listaArray;
                }

                 cout << "***********************************************************" << endl;
                  for (int i = 1; i < 1000; ++i){
                    listaCursor = new FSCursor(i);

                    for (int j = 0; j < i; ++j){
                      listaCursor->insert(0,j);
                    }

                    clock_t empiezaCursor = clock();
                    listaCursor->last();
              
                    clock_t finalCursor = clock();
                    double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                    cout << secCursor << endl;
                    delete listaCursor;
                  }
               break;
            case 5:
                /*for (int i = 1; i < 1000; ++i){
                  listaLinked = new LinkedList(i);

                  for (int j = 0; j < i; ++j){
                    listaLinked->insert(0,j);
                  }

                  clock_t empiezaLinked = clock();
                  for (int j = 0; j < i; ++j){
                    Object* ob = new Object();
                    listaLinked->indexOf(ob);
                  }
                  clock_t finalLinked = clock();
                  double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;

                  cout << secLinked << endl;
                  delete listaLinked;
                }*/
                  for (int i = 1; i < 1000; ++i){
                    listaArray = new FSArrayList(i);

                    for (int j = 0; j < i; ++j){
                      listaArray->insert(0,j);
                    }

                    clock_t empiezaLinked = clock();
                    for (int j = 0; j < i; ++j){
                      Object* ob = new Object();
                      listaArray->indexOf(ob);
                    }
                    clock_t finalLinked = clock();
                    double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                    cout << secLinked << endl;
                    delete listaArray;
                  }
                  cout << "***********************************************************" << endl;/*
                  for (int i = 1; i < 1000; ++i){
                    listaCursor = new FSCursor(i);

                    for (int j = 0; j < i; ++j){
                      listaCursor->insert(0,j);
                    }

                    clock_t empiezaCursor = clock();
                    for (int j = 0; j < i; ++j){
                      Object* ob = new Integer(j);
                      listaCursor->indexOf(ob);
                      delete ob;
                    }
                    clock_t finalCursor = clock();
                    double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                    cout << secCursor << endl;
                    delete listaCursor;
                  }*/
               break;
            case 6:
                  /*for (int i = 1; i < 1000; ++i){
                  listaLinked = new LinkedList(i);

                  for (int j = 0; j < i; ++j){
                    listaLinked->insert(0,j);
                  }

                  clock_t empiezaLinked = clock();
                  for (int j = 0; j < i; ++j){
                    listaLinked->get(j);
                  }
                  clock_t finalLinked = clock();
                  double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;

                  cout << secLinked << endl;
                  delete listaLinked;
                }
                cout << "***********************************************************" << endl;
                  for (int i = 1; i < 1000; ++i){
                    listaArray = new FSArrayList(i);

                    for (int j = 0; j < i; ++j){
                      listaArray->insert(0,j);
                    }

                    clock_t empiezaLinked = clock();
                    for (int j = 0; j < i; ++j){
                      listaArray->get(j);
                    }
                    clock_t finalLinked = clock();
                    double secLinked = double(finalLinked - empiezaLinked) / CLOCKS_PER_SEC;
                    cout << secLinked << endl;
                    delete listaArray;
                  }
                  cout << "***********************************************************" << endl;*/
                  for (int i = 1; i < 1000; ++i){
                    listaCursor = new FSCursor(i);

                    for (int j = 0; j < i; ++j){
                      listaCursor->insert(0,j);
                    }

                    clock_t empiezaCursor = clock();
                    for (int j = 0; j < i; ++j){
                      listaCursor->get(j);
                    }
                    clock_t finalCursor = clock();
                    double secCursor = double(finalCursor - empiezaCursor) / CLOCKS_PER_SEC;
                    cout << secCursor << endl;
                    delete listaCursor;
                  }
               break;
           /*case 9:
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
    cout << "3. First " << endl;
    cout << "4. Last " << endl;
    cout << "5. Index Of " << endl;
    cout << "6. Get " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}
