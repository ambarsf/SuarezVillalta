#include "object.h"
#include "tdalist.h"
#include "fsarraylist.h"
// Para tener la definición del NULL sin declarar más identificadores
// innecesarios
#include <stddef.h>
#include <iostream>
using namespace std;

// Constructor por defecto de FSArrayList
FSArrayList::FSArrayList(int capacity){
    this->capacity = capacity;
    size = -1;
}
FSArrayList::~FSArrayList(){
}
// Inserción en la lista
bool FSArrayList::insert(Object* data, int pos) {
    // Si la lista ya esta llena
    if (size == capacity) // No se pueden ingreasar mas elementos
        //return false;
        cout << "hola" << endl;
    // Si se desa meter en una posición inválida
    if (pos < 0 || pos > size)
        return false; // Fracaso en esta Operación
    if (pos != size) // Se evalua si no se esta metiendo al final
        for (int i = size; i > pos; i--) // Se recorre el arreglo de atras havia adelante
            this->data[i] = this->data[i-1]; // Se mueven los elementos para poder insertar
    cout << size << "hola" << pos << "Cap:" << capacity << endl;
    this->data[pos] = data; // Se agregar el nuevo elemento
    // Incremento del tamaño
    size++;
    // Éxito en la operación
    return true;
}
/*
* Búsqueda del índice (posición) de un objeto
* Para que esta operación tenga éxito es necesario que los objetos que sean
* insertados en la lista tengan bien definido el método equals, pues es este
* método el que determinará la igualdad de un objeto con otro.
*/
int FSArrayList::indexOf(Object* other)const {
    for (int i=0; i < size; i++){
        // Compara cada uno de los elementos con el parámetro
        if (data[i]->equals(other))
                return i;
    }
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posición válida
Object* FSArrayList::get(unsigned index)const {
    if (index < 0 || index >= size)
        return NULL;
    return data[index];
}
// Borra un elemento de la lista, dada la posición del mismo. 
Object* FSArrayList::remove(unsigned pos) {
    // Si es una posición Inválida
    if (pos < 0 || pos >= size)
        return NULL; // Indicar fracaso en la operación
    Object* retVal = data[pos];
    data[pos] = NULL;
    if (pos != size-1){ // Evalua si no se esta borrando el ultimo elemento
        for (int i = pos; i < size-1; i++)
            data[i] = data[i+1];
        data[size-1] = NULL;
    }
    size--; // Disminuir Tamaño
    return retVal; // Indicar Éxito
}
// Retorna el primer elemento de la lista, si es que hay alguno
Object* FSArrayList::first()const {
    if (!isEmpty())
        return data[0];
    return NULL;
}
// Retorna el último elemento de la lista, si es que hay alguno
Object* FSArrayList::last()const {
    if (!isEmpty())
        return data[size-1];    
    return NULL;
}
// Imprime cada uno de los elementos que hay en la lista, llamando al método
// print de cada nodo.
void FSArrayList::print()const {
    for (int i=0; i < size; i++){
        cout << data[i] << " ";
    }
}
// Retorna si la lista está llena, como nunca es así, retorna false siempre.
bool FSArrayList::isFull()const {
    return size == capacity;
}
// Retorna -1 indicando que no hay capacidad predeterminada
int FSArrayList::getCapacity()const{
    return capacity;
}
bool FSArrayList::isEmpty()const {
    return size == 0 ;
}
int FSArrayList::prev(int pos) const {
    if (pos < 1)
        return -1;
    if (!isEmpty())
        return pos-1;
    return -1;
}
int FSArrayList::next(int pos) const {
    if (pos == size)
        return -1;
    if (!isEmpty())
        return pos+1;
    return -1;
}
void FSArrayList::reset() {

}
bool FSArrayList::erase(unsigned int pos) {
    // Si es una posición Inválida
    if (pos < 0 || pos >= size)
        return false; // Indicar fracaso en la operación
    data[pos] = NULL;
    if (pos != size-1){ // Evalua si no se esta borrando el ultimo elemento
        for (int i = pos; i < size-1; i++)
            data[i] = data[i+1];
        data[size-1] = NULL;
    }
    size--; // Disminuir Tamaño
    return true; // Indicar Éxito
}