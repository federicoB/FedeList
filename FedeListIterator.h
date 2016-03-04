/* 
 * File:   FedeListIterator.h
 * Author: Federico Bertani
 *
 * Created on 13 gennaio 2016, 21.49
 */

#ifndef FEDELISTITERATOR_H
#define    FEDELISTITERATOR_H

#include <iterator>
#include "Node.hpp"

/**
 * An iterator through a Fedelist. <br>
 * It's point to a FedeList node element and has the ability to iterate through them.
 */
template<class ListType>
class FedeListIterator {
public:
    /**
     * Create an iterator that points to nothing
     */
    FedeListIterator();

    /**
     * Create a interator thats points to a node
     * @param node Node&lt;ListType*&gt;* : the node to point to.
     */
    FedeListIterator(Node<ListType> *node, int position);

    /**
     * Clone an existing iterator
     * @param orig FedeListIterator&: the iterator to clone.
     */
    FedeListIterator(const FedeListIterator &orig);

    /**
     * Destroy an interator.
     */
    virtual ~FedeListIterator();

    /**
     * Override assignemnt operator.
     * @param right FedeListIterator&lt;ListType*&gt;& : the object to assign.
     * @return FedeListIterator&lt;ListType*&gt;*: the object assigned
     */
    FedeListIterator<ListType> &operator=(const FedeListIterator<ListType> &right);

    /**
     * Ovverride direct access operator.This browse the list until the given position is found.
     * @param position int: the position to get .
     * @return FedeListIterator&lt;ListType*&gt;* : a pointer to the element searched
     */
    FedeListIterator<ListType> &operator[](const int position);

    /**
     * Get the node pointed by the iterator.
     * @return FedeListIterator&lt;ListType*&gt;*: the node pointed by the iterator.
     */
    Node<ListType> *operator*();

    /**
    * Access the node pointed by the iterator.
    * @return FedeListIterator&lt;ListType*&gt;*: the node pointed by the iterator.
    */
    Node<ListType> *operator->();

    /**
     * Compare two Iterators, if they point to the same node they are the same iterator.
     * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
     * @return bool: true if the iterators are the same, false otherwise.
     */
    bool operator==(const FedeListIterator<ListType> &right);

    /**
     * Compare two iterator, if they point to different nodes they are different iterators.
     * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
     * @return bool:true if the iterator are the same, false otherwise..
     */
    bool operator!=(const FedeListIterator<ListType> &right);

    /**
     * Compare two iterators and check if an iterator is pointing at a node that is behind onother.
     * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
     * @return bool: true if the iterator is smaller, false otherwise.
     */
    bool operator<(const FedeListIterator<ListType> &right);

    /**
      * Compare two iterators and check if an iterator is pointing at a node that is behind onother or the same.
      * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
      * @return bool: true if the iterator is smaller or equal, false otherwise.
      */
    bool operator<=(const FedeListIterator<ListType> &right);

    /**
      * Compare two iterators and check if an iterator is pointing at a node that is ahead onother.
      * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
      * @return bool: true if the iterator is greater, false otherwise.
      */
    bool operator>(const FedeListIterator<ListType> &right);

    /**
      * Compare two iterators and check if an iterator is pointing at a node that is ahead onother or they are the same.
      * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to compare
      * @return bool: true if the iterator is greater or equal false otherwise.
      */
    bool operator>=(const FedeListIterator<ListType> &right);

    /**
     * Create a new iterator that point to the position in the list that is the sum of the position of two others iterators.
     * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to sum
     * @return FedeListIterator&lt;ListType*&gt;*: the new iterator.
     */
    FedeListIterator<ListType> operator+(const FedeListIterator<ListType> &right);

    /**
     * Create a new iterator that point to the position in the list that is the difference of the position of two other iterators.
     * @param right FedeListIterator&lt;ListType*&gt;*: the iterator to subtract
     * @return FedeListIterator&lt;ListType*&gt;*: the new iterator.
     */
    FedeListIterator<ListType> operator-(const FedeListIterator<ListType> &right);

    /**
     * Advance the iterator to a position but return the old operator.
     * @return FedeListIterator&lt;ListType*&gt;*: the old iterator.
     */
    FedeListIterator<ListType> &operator++();

    /**
     * Advance the iterator to a position and return it.
     * @return FedeListIterator&lt;ListType*&gt;*: the iterator increased.
     */
    FedeListIterator<ListType> &operator++(int);

    /**
     * Decrease the iterator to a position but return the old iterator.
     * @return FedeListIterator&lt;ListType*&gt;*: the old iterator.
     */
    FedeListIterator<ListType> &operator--();

    /**
     * Decrese the iterator to a position and return it.
     * @return FedeListIterator&lt;ListType*&gt;*: the iterator increased.
     */
    FedeListIterator<ListType> &operator--(int);

    void setNode(Node<ListType> *node, int position);

    int getPosition() const;

    void setPosition(int position);


private:
    int position;
    Node<ListType> *pointer;
};

#include "FedeListIterator.cpp"

#endif	/* FEDELISTITERATOR_H */

