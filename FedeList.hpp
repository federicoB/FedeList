/* 
 * File:   FedeList.h
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 *
 * Created on 16 novembre 2015, 19.01
 */

#ifndef FEDELIST_H
#define	FEDELIST_H

#include <stdexcept>
#include "Node.hpp"
#include "FedeListIterator.h"

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
     * Constructs a FedeList with only a node containg the given element.
     * @param element ListType: the element to put as first node.
     */
    FedeList(ListType element);
    
    /**
     * Create a FedeList copying it from an another FedeList.
     * @param orig FedeList&lt;ListType*&gt;*: the fedelist to copy.
     */
    FedeList(const FedeList<ListType>& orig);
    
    /**
     * Destroy a Fedelist.
     */
    virtual ~FedeList();
    
    /**
     * Initialize FedeList internal state.
     */
    void init();
    
    /**
     * Add an element in head of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_front(ListType element);
    
     /**
     * Add an element in tail of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_back(ListType element);
    
    /**
     * Insert an element in the given position.
     * The element is inserted <b>before</b> the element that may be in the position.
     * @param element ListType: the element to insert.
     * @param position int: the position in the list where insert the element.
     * @return FedeList*: a pointer to the list object for method chaining.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    FedeList* insert(ListType element,int position);
    
    /**
     * Remove an element in the head of the list and returns it.
     * throw exception if the list is empty.
     * @return ListType*: the element in the head of the list.
     * @throws out_of_range: throw a out of range exception if the list is empty.
     */
    ListType pop_front();
    
    /**
     * Remove an element in the tail of the list and return it.
     * @return ListType*: the element in the tail of the list.
     * @throws out_of_range: throw a out of range exception if the list is empty.
     */
    ListType pop_back();
    
    /**
     * Get an element from the list in the given position.
     * @param position: the position in the list of the element to get.
     * @return ListType*: the element from the list in the given position.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    ListType get(int position);
    
    /**
     * Remove from the list the element in the given position.
     * @param position int: the position in the list of the element to remove.
     * @return FedeList*: a pointer to the list object for method chaining.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    FedeList* remove(int position);

    /**
    * Remove from the list the first occurrence of the element that is equal to the element given.
    * NOTE: list type comparison is made through == operator.
    * @param element ListType: the element used for the comparison.
    * @return FedeList*: a pointer to the list object for method chaining.
    */
    FedeList* removeByElement(ListType element); 
    
    /**
     * Return the size of the list.
     * @return int: the size of the list.
     */
    int getSize() const;

    //define Node<ListType>* as NodePointer
    typedef Node<ListType> *NodePointer;

    /**
     * Sort the elements of the list.
     * It use Bubble-Sort algoritm.
     * If the elements on the list are not comparable undefined behaviour occurr.
     */
    void sort();
    
protected:
    //a pointer that always point to the head of the list
    FedeListIterator<ListType> headCursor;
    //a pointer that always point to the tail of the list
    FedeListIterator<ListType> tailCursor;
    //a sliding cursor
    FedeListIterator<ListType> cursor;
    //the lenght of the list
    int listSize;
    
    /**
     * This set the cursor as near as possible to the searched position.
     * @param position int: the position of the searched element.
     */
    void prepareSearch(int position);
    
    /**
     * Move the cursor to the node in the given position.
     * @param position int: the position of the node to get.
     * @return NodePointer: a pointer to the node to get.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    void moveCursor(int position);
    
    /**
     * Check if the position given is valid.
     * @param position int: the position to check.
     * @return true is the position is valid, false otherwise.
     */
    bool isValidPosition(int position);
};

#include "FedeList.cpp"

#endif	/* FEDELIST_H */

