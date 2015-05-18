#include "object.h"
#include "tdalist.h"
#include "linkedlist.h"
// Para tener la definici�n del NULL sin declarar m�s identificadores
// innecesarios
#include <stddef.h>

// Constructor por defecto de LinkedList
LinkedList::LinkedList(unsigned int capacity){
    this->capacity = capacity;
    head = NULL;
    next = NULL;
}
// Super Destructor de LinkedList, n�tese que llamar� al destructor
// de la clase DLLNode, que liberar� todos los nodos siguientes...
LinkedList::~LinkedList(){
    if (head)
        delete head;
}
/*
* Inserci�n en la lista
* En esta operaci�n se consideran cuatro casos generales de inserci�n:
* (A) La Lista est� Vac�a
* (B) Se desea Insertar antes de head (pos = 0)
* (C) Se desea Insertar en Medio de la Lista
* (D) Se desea Insertar al Final (pos = size)
*/
bool LinkedList::insert(Object* data, int pos) {
    // Si se desa meter en una posici�n inv�lida
    if (pos < 0 || pos > size)
        return false; // Fracaso en esta Operaci�n
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
    // Incremento del tama�o
    size++;
    // �xito en la operaci�n
    return true;
}
/*
* B�squeda del �ndice (posici�n) de un objeto
* Para que esta operaci�n tenga �xito es necesario que los objetos que sean
* insertados en la lista tengan bien definido el m�todo equals, pues es este
* m�todo el que determinar� la igualdad de un objeto con otro.
*/
int LinkedList::indexOf(Object* other)const {
    Node* tmp = head;
    for (int i=0; i < size; i++){
        // Compara cada uno de los elementos con el par�metro
        if (tmp.data->equals(other))
                return i;
        tmp = tmp.next;
    }
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posici�n v�lida
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
* Borra un elemento de la lista, dada la posici�n del mismo. Se consideran
* tres casos:
* (A) El Elemento es la Cabeza
* (B) El Elemento es el �ltimo
* (C) El Elemento est� en Medio
* Es importante recalcar que para borrar un elemento es necesario primero
* desenlazarlo de la lista y luego liberar su memoria, pues en caso contrario
* liberar�amos todos los elementos siguiente a este elemento.
*/
bool LinkedList::erase(unsigned pos) {
    // Si es una posici�n Inv�lida
    if (pos < 0 || pos >= size)
        return false; // Indicar fracaso en la operaci�n
    Node* tmp =  new Node;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmp = head->next;
        head->next = NULL;
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == size - 1){ // Desea Borrar el �ltimo
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
    size--; // Disminuir Tama�o
    return true; // Indicar �xito
}
// Retorna el anterior a la posici�n pos
// Implementado de la manera m�s sencilla, pues podr�a haberse usado
// DLLNode*
int LinkedList::prev(int pos) const {
    return pos - 1;
}
// Retorna el siguiente a la posici�n pos
// Implementado de la manera m�s sencilla, pues podr�a haberse usado
// DLLNode*
int LinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca size en cero, y la cabeza
// en NULL, o sea que hace un poco m�s que el destructor.
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
// Retorna el �ltimo elemento de la lista, si es que hay alguno
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

