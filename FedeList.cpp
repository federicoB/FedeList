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
template <class ListType> 
FedeList<ListType>* FedeList<ListType>::push_front(ListType tipolista) throw (exception) {
    if (tipolista!=NULL) {
        if (headCursor!=NULL) {
            NodePointer tmp = new Node<ListType>(tipolista,headCursor);
            headCursor->setPrev(tmp);
            headCursor = tmp;
        } else headCursor = new Node<ListType>(tipolista);
    } else throw(new exception());
};
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