/* 
 * File:   Node.cpp
 * Author: fede
 * 
 * Created on 18 dicembre 2015, 14.55
 */

#include "Node.hpp"

template <class ListType>
Node<ListType>::Node(ListType* value, Node* prev, Node* next) {
    if (value==NULL) throw (new exception());
}

template <class ListType>
Node<ListType>::Node(const Node& orig) {
}

