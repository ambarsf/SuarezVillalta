#include "object.h"
#include "tdalist.h"
#include "linkedlist.h"
// Para tener la definición del NULL sin declarar más identificadores
// innecesarios
#include <stddef.h>

// Constructor por defecto de LinkedList
LinkedList::LinkedList(unsigned int capacity){
    this->capacity = capacity;
    head = NULL;
    next = NULL;
}
// Super Destructor de LinkedList, nótese que llamará al destructor
// de la clase DLLNode, que liberará todos los nodos siguientes...
LinkedList::~LinkedList(){
    if (head)
        delete head;
}
/*
* Inserción en la lista
* En esta operación se consideran cuatro casos generales de inserción:
* (A) La Lista está Vacía
* (B) Se desea Insertar antes de head (pos = 0)
* (C) Se desea Insertar en Medio de la Lista
* (D) Se desea Insertar al Final (pos = size)
*/
bool LinkedList::insert(Object* data, int pos) {
    // Si se desa meter en una posición inválida
    if (pos < 0 || pos > size)
        return false; // Fracaso en esta Operación
    Node* neo= new Node();
    if (neo==NULL){
        throw "No Memory";
    }
    neo.data=data;
    neo.next=NULL;
    if (!head){
        head=neo;
    }else{
        if (pos==0){
            neo.next=head;
            head=neo;
        }else{
            Node* tmp=head;
            for (int i = 0; i < pos-1; i++)
            {
                tmp=tmp.next;
            }
            neo.next=tmp.next;
            tmp.next=neo;
        }
    }
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
int LinkedList::indexOf(Object* other)const {
    Node* tmp = head;
    for (int i=0; i < size; i++){
        // Compara cada uno de los elementos con el parámetro
        if (tmp.data->equals(other))
                return i;
        tmp = tmp.next;
    }
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posición válida
Object* LinkedList::get(unsigned index)const {
    if (head==NULL){
        throw "Lista no tiene Elementos";
    }
    if (index>size){
        throw "Posicion no valida";
    }
    Node* tmp= head;
    for (int i = 0; i < index; i++)
    {
        tmp=tmp.next;
    }
    return tmp.data;
}
/*
* Borra un elemento de la lista, dada la posición del mismo. Se consideran
* tres casos:
* (A) El Elemento es la Cabeza
* (B) El Elemento es el Último
* (C) El Elemento está en Medio
* Es importante recalcar que para borrar un elemento es necesario primero
* desenlazarlo de la lista y luego liberar su memoria, pues en caso contrario
* liberaríamos todos los elementos siguiente a este elemento.
*/
bool LinkedList::erase(unsigned pos) {
    // Si es una posición Inválida
    if (pos < 0 || pos >= size)
        return false; // Indicar fracaso en la operación
    Node* tmp =  new Node;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmp = head->next;
        head->next = NULL;
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == size - 1){ // Desea Borrar el último
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->next;
        // Desenlazar
        Node* toErase = tmp->next;
        tmp->next = NULL;
        // Liberar Memoria
        delete toErase;
    }else { // Desea Borrar de enmedio
        // Recorrer hasta el nodo anterior al que se desea borrar
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->next;
        // Desenlazar
        Node* toErase = tmp->next;
        tmp->next = toErase->next;
        toErase->next = NULL;
        // Liberar Memoria
        delete toErase;
    }
    size--; // Disminuir Tamaño
    return true; // Indicar Éxito
}
// Retorna el anterior a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int LinkedList::prev(int pos) const {
    return pos - 1;
}
// Retorna el siguiente a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int LinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca size en cero, y la cabeza
// en NULL, o sea que hace un poco más que el destructor.
void LinkedList::reset() {
    if (head)
        delete head;
    head = NULL;
    size = 0;
}
// Retorna el primer elemento de la lista, si es que hay alguno
Object* LinkedList::first()const {
    if (head)
        return head.data;
    return NULL;
}
// Retorna el último elemento de la lista, si es que hay alguno
Object* LinkedList::last()const {
    if (!head)
        return NULL;
    Node* tmp = head;
    for (int i=0; i < size; i++)
        tmp = tmp.next;
    return tmp.data;
}

void LinkedList::print()const {
    Node* tmp = head;
    for (int i=0; i < size; i++){
        tmp->print();
        tmp = tmp->getNext();
    }
}

bool LinkedList::isFull()const {
    if (size==capacity){
        return true;
    }else{
        return false;
    }
}

int LinkedList::getCapacity()const{
    return capacity;
}

