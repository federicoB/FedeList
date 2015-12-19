/* 
 * File:   Node.h
 * Author: fede
 *
 * Created on 18 dicembre 2015, 14.55
 */

#ifndef NODE_H
#define	NODE_H

#include <exception>
#include <stddef.h>

template <class ListType>
class Node {
public:
    Node(ListType* value,Node* prev,Node* next);
    Node(const Node& orig);
    ListType getValue();
    virtual ~Node();
private:
    ListType value;
    Node* next;
    Node* prev;
};

#endif	/* NODE_H */

