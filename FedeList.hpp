/* 
 * File:   FedeList.h
 * Author: Federico Bertani
 *
 * Created on 16 novembre 2015, 19.01
 */

#ifndef FEDELIST_H
#define	FEDELIST_H

#include <exception>
#include "Node.hpp"

using namespace std;

/**
 * FedeList in a multipurpouse list implemented with a template class.
 * It's offers static adding time and linear searching time.
 * @tparam the type of element of the list.
 */
template <class ListType> 
class FedeList {
    public:
    /**
     * Create an empty FedeList.
     */
    FedeList();
    
    /**
     * Create a FedeList with only a node containg the given element.
     * @param element ListType: the element to put as first node
     */
    FedeList(ListType element) throw (exception);
    
    /**
     * Clone an existing Fedelist
     * @param orig Fedelist&: the Fedelist to clone
     */
    FedeList(const FedeList& orig) throw (exception);
    
    /**
     * Destroy a Fedelist.
     */
    virtual ~FedeList(); 
    
    /**
     * Add an element in head of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_front(ListType element) throw (exception);
    
     /**
     * Add an element in tail of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_back(ListType element) throw (exception);
    
    /**
     * Remove an element in the head of the list and return it.
     * @return ListType*: the element in the head of the list.
     */
    ListType* pop_front() throw (exception);
    
    /**
     * Remove an element in the tail of the list and return it.
     * @return ListType*: the element in the tail of the list.
     */
    ListType* pop_back() throw (exception);
    
    /**
     * Get an element from the list in the given position.
     * @param position: the position in the list of the element to get.
     * @return ListType*: the element from the list in the given position.
     */
    ListType* get(int position) throw (exception);
    
    /**
     * Get an element from the list that is equal to the element given.
     * @param element ListType: the element for the comparison.
     * @return ListType*: the element from the list that is equal to the element given.
     */
    ListType* getByElement(ListType element) throw (exception);
    
    /**
     * Remove from the list the element in the given position.
     * @param position int: the position in the list of the element to remove.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* remove(int position) throw (exception);  
    
     /**
     * Remove from the list the element that is equal to the element given.
     * @param element ListType: the element used for the comparison.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* removeByElement(ListType element) throw (exception); 
protected:
    typedef Node<ListType>* NodePointer; //a type that represent a pointer to a Node
    NodePointer headCursor; //a pointer that always point to the head of the list
    NodePointer tailCursor; //a pointer that always point to the tail of the list
    NodePointer cursor; //a pointer to a node that read the list up and down
    int cursorPosition; //the position of the cursor inside of the list, 0 based
    int listLength; //the lenght of the list starting from 1
   // void prepareSearch(int posizione) throw (exception);
   // NodePointer search(int posizione);
};

#include "FedeList.cpp"

#endif	/* FEDELIST_H */

