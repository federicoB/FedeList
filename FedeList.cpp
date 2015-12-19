/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * 
 * Created on 8 novembre 2015, 13.46
 */

#include "FedeList.hpp"

template <class ListYpe> 
FedeList<ListYpe>::FedeList() {
    headCursor = NULL;
    cursor = headCursor;
    tailCursor = headCursor;
    cursorPosition = 0;
    listLength = 0;
};
//
//template <class ListType> 
//FedeList<ListType>::~FedeList() {
//    
//}
//
//template <class ListType> 
//void FedeList<ListType>::add(ListType tipolista) {
//    if (head == NULL) {
//        head = new Elemento();
//        head->next = NULL;
//        head->valore = tipolista;
//        cursor = head;
//        tailCursor = head;
//        cursorPosition = 0;
//        listLength++;
//    } else {
//        Elemento* p = new Elemento;
//        p->valore = tipolista;
//        p->next = NULL;
//        tailCursor->next = p;
//        tailCursor = p;
//        listLength++;
//    }
//};
//
////ritorna l'elemento della lista in una certa posizione
//template <class TipoLista> 
//TipoLista FedeList<TipoLista>::get(int posizione) throw (exception) {
//    prepareSearch(posizione);
//    return (search(posizione))->valore;
//};
//
//template <class TipoLista> 
//void FedeList<TipoLista>::remove(NodePointer p, int posizione) {
//    cursor = get(posizione-1); //ottengo l'elemento precedente
//    NodePointer elementToDelete = cursor->next;
//    NodePointer cursorNextNext = elementToDelete->next;
//    cursor->next = cursorNextNext;
//    delete elementToDelete;
//};
//
//template <class TipoLista> 
//void FedeList<TipoLista>::prepareSearch(int posizione) throw (exception) {
//    if (posizione >= 0) {
//        if (posizione < cursorPosition) {
//            cursor = head; //sposto il cursore che punta alla testa
//            cursorPosition = 0;
//        }
//    } else throw (exception());
//}
//
//template <class TipoLista>
//typename FedeList<TipoLista>::NodePointer FedeList<TipoLista>::search(int posizione) {
//    if (cursorPosition == posizione) {
//        return cursor;
//    } else {
//        cursorPosition++;
//        cursor = cursor->next;
//        search(posizione);
//    }
//}