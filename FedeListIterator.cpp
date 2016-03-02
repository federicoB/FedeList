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

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator[](const int position) {
    //check if the position is ahead to the cursor
    bool isPositionAhead = this->position < position;
    //while the cursor position is not equal than the position
    while (this->position != position) {
        //if the position is ahead
        if (isPositionAhead) {
            *this++;
        }
            //else (position is before the cursor)
        else {
            *this--;
        }
    }
}

template <class ListType>
Node<ListType> &FedeListIterator<ListType>::operator*() {
    return *this->pointer;
}

template <class ListType>
bool FedeListIterator<ListType>::operator==(const FedeListIterator<ListType> &right) {
    return (this->position==right.position);
}

template <class ListType>
bool FedeListIterator<ListType>::operator!=(const FedeListIterator<ListType> &right) {
    return !(*this==right);
}

template <class ListType>
bool FedeListIterator<ListType>::operator<(const FedeListIterator<ListType> &right) {
    return (this->position<right.position);
}

template <class ListType>
bool FedeListIterator<ListType>::operator<=(const FedeListIterator<ListType> &right) {
    return (*this<right) || (*this==right);
}

template <class ListType>
bool FedeListIterator<ListType>::operator>(const FedeListIterator<ListType> &right) {
    return !(*this<right) && !(*this==right);
}

template <class ListType>
bool FedeListIterator<ListType>::operator>=(const FedeListIterator<ListType> &right) {
    return !(*this<right);
}

template <class ListType>
FedeListIterator<ListType> FedeListIterator<ListType>::operator+(const FedeListIterator<ListType> &right) {
    return FedeListIterator();
}

template <class ListType>
FedeListIterator<ListType> FedeListIterator<ListType>::operator-(const FedeListIterator<ListType> &right) {
    return FedeListIterator();
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator++() {
    FedeListIterator<ListType>& oldOne = *this;
    //move the cursor ahead
    this->pointer = this->pointer -> getNext();
    //increase the cursor position
    this->position++;
    return oldOne;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator++(int i) {
    //move the cursor ahead
    this->pointer = this->pointer -> getNext();
    //increase the cursor position
    this->position++;
    return *this;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator--() {
    FedeListIterator<ListType>& oldOne = *this;
    //move the cursor back
    this->pointer = this->pointer -> getPrev();
    //decrease the cursor position
    this->position--;
    return oldOne;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator--(int i) {
    //move the cursor back
    this->pointer = this->pointer -> getPrev();
    //decrease the cursor position
    this->position--;
    return *this;
}

template<class ListType>
FedeListIterator<ListType>& FedeListIterator<ListType>::operator=(const FedeListIterator<ListType>& right) {
        // Check for self-assignment!
        if (this == &right) // Same object?
            return *this; // Yes, so skip assignment, and just return *this.
        // Deallocate, allocate new space, copy values...
        //copy pointers
        this->pointer = right.pointer;
        return *this;
}

