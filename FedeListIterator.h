/* 
 * File:   FedeListIterator.h
 * Author: Federico Bertani
 *
 * Created on 13 gennaio 2016, 21.49
 */

#ifndef FEDELISTITERATOR_H
#define	FEDELISTITERATOR_H

#include <iterator>

/**
 * An iterator through a Fedelist. <br>
 * It's point to a FedeList element and has the ability to iterate through them.
 */
template <class ListType>
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
    FedeListIterator(Node<ListType>* node,int position);
    
    /**
     * Clone an existing iterator
     * @param orig FedeListIterator&: the iterator to clone.
     */
    FedeListIterator(const FedeListIterator& orig);
    
    /**
     * Destroy and interator.
     */
    virtual ~FedeListIterator();
    
    /**
     * Override assignemnt operator.
     * @param right FedeListIterator&lt;ListType*&gt;& : the object to assign.
     * @return FedeListIterator&lt;ListType*&gt;& : the object assigned
     */
    FedeListIterator<ListType>& operator=(const FedeListIterator<ListType>& right);
    
    //TODO override operator ++,--, [] , == , < , > ...
    
    void setNode(Node<ListType>& node,int position);
    
private:
    int position;
    Node<ListType>* pointer;
};

#endif	/* FEDELISTITERATOR_H */

