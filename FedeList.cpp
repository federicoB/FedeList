/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * 
 * Created on 8 novembre 2015, 13.46
 */

#ifndef FEDELIST_CPP
#define	FEDELIST_CPP

#include "FedeList.hpp"

template <class ListType> 
FedeList<ListType>::FedeList() {
    headCursor = NULL;
    cursor = headCursor;
    tailCursor = headCursor;
    cursorPosition = 0;
    listLength = 0;
};

template <class ListType> 
FedeList<ListType>::~FedeList() {
    cursor = headCursor;
    cursorPosition = 0; //TODO creating a class cursor that automatically do this.
    NodePointer cursorToDelete;
    for (int i=0;i<listLength;i++) {
        cursorToDelete = cursor;
        cursor = cursor->getNext();
        cursorPosition++;
        delete cursorToDelete;
    }
}

template <class ListType> 
FedeList<ListType>* FedeList<ListType>::push_front(ListType element) throw (exception) {
    if (element!=NULL) {
        if (headCursor!=NULL) {
            NodePointer tmp = new Node<ListType>(element,NULL,headCursor);
            headCursor->setPrev(tmp);
            headCursor = tmp;
        } else headCursor = new Node<ListType>(element);
    } else throw(new exception());
    return (this);
};

template <class ListType> 
FedeList<ListType>* FedeList<ListType>::push_back(ListType element) throw (exception) {
    if (element!=NULL) {
        if (tailCursor!=NULL) {
            NodePointer tmp = new Node<ListType>(element,tailCursor);
            tailCursor->setNext(tmp);
            tailCursor = tmp;
        } else tailCursor = new Node<ListType>(element);
    } else throw(new exception());
    return (this);
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

#endif	/* FEDELIST_CPP */