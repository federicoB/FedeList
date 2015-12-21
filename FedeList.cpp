/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * 
 * Created on 8 novembre 2015, 13.46
 */

#ifndef FEDELIST_CPP
#define	FEDELIST_CPP

#include <cstdlib> //for abs() function
#include "FedeList.hpp"

template <class ListType>
FedeList<ListType>::FedeList() {
    headCursor = NULL;
    cursor = headCursor;
    tailCursor = headCursor;
    cursorPosition = 0;
    listSize = 0;
};

template <class ListType>
FedeList<ListType>::FedeList(ListType element) {
    FedeList();
    this->push_back(element);
    listSize++;
}

template <class ListType>
FedeList<ListType>::FedeList(const FedeList& orig) {
    FedeList();
    int originSize = orig.getSize();
    for (int i = 0; i < originSize; i++) {
        this->push_back(*orig.get(i));
        listSize++;
    }
}

template <class ListType>
FedeList<ListType>::~FedeList() {
    cursor = headCursor;
    cursorPosition = 0; //TODO creating a class cursor that automatically do this.
    NodePointer cursorToDelete;
    for (int i = 0; i < listSize; i++) {
        cursorToDelete = cursor;
        cursor = cursor->getNext();
        cursorPosition++;
        delete cursorToDelete;
        listSize--;
    }
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_front(ListType element) {
    if (headCursor != NULL) {
        //TODO fix that mess(is it needed?)
        NodePointer tmp = new Node<ListType>(&element, (Node<ListType>*)NULL, headCursor);
        headCursor->setPrev(tmp);
        headCursor = tmp;
    } else {
        headCursor = new Node<ListType>(&element);
        tailCursor = headCursor;
        cursor = headCursor;
    }
    listSize++;
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_back(ListType element) {
    if (tailCursor != NULL) {
        NodePointer tmp = new Node<ListType>(&element, tailCursor);
        tailCursor->setNext(tmp);
        tailCursor = tmp;
    } else {
        tailCursor = new Node<ListType>(&element);
        tailCursor = headCursor;
        cursor = headCursor;
    }
    listSize++;
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::insert(ListType element, int position) throw(exception) {
    moveCursor(position);
    Node* node = new Node(element,cursor->getPrev(),cursor);
    cursor->getPrev()->setNext(node);
    cursor->setPrev(node);
    cursorPosition++;
    return (this);
};

template <class ListType>
ListType* FedeList<ListType>::pop_front() throw (exception) {
    if (listSize > 0) {
        ListType* valueToReturn = new ListType;
        *valueToReturn = headCursor->getValue();
        NodePointer toDelete = headCursor;
        if (listSize > 1) {
            headCursor = headCursor->getNext();
        } else {
            headCursor = NULL;
            tailCursor = NULL;
            cursor = NULL;
        }
        delete toDelete;
        listSize--;
        return valueToReturn;
    } else throw (exception());
}

template <class ListType>
ListType* FedeList<ListType>::pop_back() throw (exception) {
    if (listSize > 0) {
        ListType* valueToReturn = new ListType;
        *valueToReturn = tailCursor->getValue();
        NodePointer toDelete = tailCursor;
        if (listSize > 1) {
            tailCursor = tailCursor->getPrev();
        } else {
            headCursor = NULL;
            tailCursor = NULL;
            cursor = NULL;
        }
        delete toDelete;
        listSize--;
        return valueToReturn;
    } else throw (exception());
}

template <class ListType>
int FedeList<ListType>::getSize() const {
    return listSize;
};

template <class ListType>
void FedeList<ListType>::prepareSearch(int position) {
#define cursorDistance abs(cursorPosition-position)
#define headDistance position
#define tailDistance (listSize-position)   
    //if the distance between the position to get and the head/tail is less thant the distance
    //between cursor and position we can make an optimization.
    if ((headDistance < cursorDistance) && (tailDistance < cursorDistance))
        if (headDistance <= tailDistance) {
            cursor = headCursor;
            cursorPosition = 0;
        } else {
            cursor = tailCursor;
            cursorPosition = listSize;
        }
}

template<class ListType>
void FedeList<ListType>::moveCursor(int position) throw (exception) {
    if (checkPosition(position)) {
        prepareSearch(position);
        bool isPositionAhead = cursorPosition<position;
        while (cursorPosition != position) {
            if (isPositionAhead) {
                cursor = cursor->getNext();
            } else {
                cursor = cursor->getNext();
            }
        }
    }
}

template<class ListType>
bool FedeList<ListType>::checkPosition(int position) throw (exception) {
    if ((position >= 0) && (position <= listSize)) return (true);
    else throw (exception());
}



#endif	/* FEDELIST_CPP */