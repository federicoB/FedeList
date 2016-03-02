/* 
 * File:   FedeListIterator.cpp
 * Author: fede
 * 
 * Created on 13 gennaio 2016, 21.49
 */

#include "FedeListIterator.h"

template <class ListType>
FedeListIterator<ListType>::FedeListIterator() {
    //set the iterator to point nothing
    this->pointer = NULL;
    //-1 stands for a inexinsting position
    this->position = -1;
}

template <class ListType>
FedeListIterator<ListType>::FedeListIterator(Node<ListType>* node,int position) {
    //assign the given node
    this->pointer = node;
    //assign the given position
    this->position = position;
}

template <class ListType>
FedeListIterator<ListType>::FedeListIterator(const FedeListIterator& orig) {
    //clone the pointer
    this->pointer = orig.pointer;
    //clone the position
    this->position = orig.position;
}

template <class ListType>
FedeListIterator<ListType>::~FedeListIterator() {
    //do nothing because pointer is automatically destroyed.
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator[](const int position) {
    //check if the position is ahead to the iterator
    bool isPositionAhead = this->position < position;
    //while the iterator position is not equal than the position
    while (this->position != position) {
        //if the position is ahead
        if (isPositionAhead) {
            //advance the iterator
            *this++;
        }
            //else (position is before the iterator)
        else {
            //decrease the iterator
            *this--;
        }
    }
    return *this;
}

template <class ListType>
Node<ListType> &FedeListIterator<ListType>::operator*() {
    //return the node pointed by the iterator
    return *this->pointer;
}

template <class ListType>
bool FedeListIterator<ListType>::operator==(const FedeListIterator<ListType> &right) {
    //compare the two position, if the two iterators point to the same position they are the same object
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
    //TODO better implementation cloning the nearest of the two
    //create e new iterator
    FedeListIterator<ListType> newIterator = FedeListIterator<ListType>();
    //move the new iterator
    newIterator[this->position+right.position];
    return newIterator;
}

template <class ListType>
FedeListIterator<ListType> FedeListIterator<ListType>::operator-(const FedeListIterator<ListType> &right) {
    //TODO better implementation cloning the nearest of the two
    //create e new iterator
    FedeListIterator<ListType> newIterator = FedeListIterator<ListType>();
    //move the new iterator
    newIterator[this->position-right.position];
    return newIterator;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator++() {
    //save the current iterator state in a variabile
    FedeListIterator<ListType>& oldOne = *this;
    //move the iterator ahead
    this->pointer = this->pointer -> getNext();
    //increase the iterator position
    this->position++;
    //return the old iterator
    return oldOne;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator++(int i) {
    //move the iterator ahead
    this->pointer = this->pointer -> getNext();
    //increase the iterator position
    this->position++;
    return *this;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator--() {
    //save the current iterator state in a variabile
    FedeListIterator<ListType>& oldOne = *this;
    //move the iterator back
    this->pointer = this->pointer -> getPrev();
    //decrease the iterator position
    this->position--;
    //return the old iterator
    return oldOne;
}

template <class ListType>
FedeListIterator<ListType> &FedeListIterator<ListType>::operator--(int i) {
    //move the iterator back
    this->pointer = this->pointer -> getPrev();
    //decrease the iterator position
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

template<class ListType>
void FedeListIterator<ListType>::setNode(Node<ListType> &node, int position) {
    //assign the given node
    this->pointer = &node;
    //assign the given position
    this->position = position;
}
