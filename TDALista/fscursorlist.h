#pragma once
#include "object.h"
#include "tdalist.h"
/*
* Declaración de la Clase FSCursor, que es una implementación del TDAList
* utilizando listas doblemente enlazadas. Nótese la herencia en esta clase.
* Nótese así mismo, que están todas las operaciones virtuales puras de la
* clase TDAList, pues acá se tendrán que definir cada una de estas.
*/
class FSCursor : public TDAList{
    struct Row{
        int next, prev;
        Object* data;
    } ;
    int head;
    Row* rows;
    int capacity;
    int size;

  public:
    FSCursor(unsigned int);
    virtual ~FSCursor();
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
    int avail() const;
};

