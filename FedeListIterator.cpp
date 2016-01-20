/* 
 * File:   FedeListIterator.cpp
 * Author: fede
 * 
 * Created on 13 gennaio 2016, 21.49
 */

#include "FedeListIterator.h"

template <class ListType>
FedeListIterator<ListType>::FedeListIterator() {
    this->pointer = NULL;
    this->position = -1;
}

template <class ListType>
FedeListIterator<ListType>::FedeListIterator(Node<ListType>* node,int position) {
    this->pointer = node;
    this->position = position;
}

template <class ListType>
FedeListIterator<ListType>::FedeListIterator(const FedeListIterator& orig) {
    this->pointer = orig.pointer;
    this->position = orig.position;
}

template <class ListType>
FedeListIterator<ListType>::~FedeListIterator() {
    //do nothing because pointer is automatically destroyed.
}

template<class ListType>
FedeListIterator<ListType>& FedeListIterator<ListType>::operator=(const FedeListIterator<ListType>& right) {
        // Check for self-assignment!
        if (this == &right) // Same object?
            return *this; // Yes, so skip assignment, and just return *this.
        // Deallocate, allocate new space, copy values...
        //copy pointers
        this->pointer = right->pointer;
        return *this;
}

