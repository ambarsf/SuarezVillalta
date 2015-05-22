#pragma once
#include "object.h"
#include "tdalist.h"
/*
* Declaración de la Clase FSArrayList, que es una implementación del TDAList
* utilizando listas doblemente enlazadas. Nótese la herencia en esta clase.
* Nótese así mismo, que están todas las operaciones virtuales puras de la
* clase TDAList, pues acá se tendrán que definir cada una de estas.
* El único miembro que tiene esta clase es head, que representa la cabeza de
* la lista, no es necesario tener size, pues lo heredamos de la clase base.
*/
class FSArrayList : public TDAList{
  protected:
    int capacity;
    int size;
    Object ** data;
  public:
    FSArrayList(int);
    virtual ~FSArrayList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    Object* remove(unsigned) ;
    virtual bool erase(unsigned) ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
    bool isEmpty()const ;
};

