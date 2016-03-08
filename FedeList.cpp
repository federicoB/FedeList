/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 * 
 * Created on 8 novembre 2015, 13.46
 */

#ifndef FEDELIST_CPP
#define	FEDELIST_CPP

#include <cstdlib>
#include "FedeList.hpp"

template <class ListType>
FedeList<ListType>::FedeList(){
    //call the initialization function
    this -> init();
};

template <class ListType>
FedeList<ListType>::FedeList(ListType element){
    //call the initialization function
    this -> init();
    //push the given element
    this -> push_back(element);
}

template <class ListType>
FedeList<ListType>::FedeList(const FedeList& orig) {
    //call the initialization function
    this -> init();
    //i can't access orig nodes 'cause it would change orig and it's const for c++ standard.
    //so i create a tmpCopy that point to same nodes but i can modify it.
    FedeList<ListType> tmpCopy = FedeList<ListType>();
    tmpCopy.headCursor = orig.headCursor;
    tmpCopy.cursor = orig.headCursor;
    tmpCopy.listSize = orig.listSize;
    //save the origin size in a variabile because it would be modified by the loop
    int originSize = orig.getSize();
    //for the origin size
    for (int i = 0; i < originSize; i++) {
        //add the element from the tmpy copy to current FedeList
        this->push_back(tmpCopy.get(i));
    }
}

template <class ListType>
FedeList<ListType>::~FedeList(){
    //set current node as the head
    FedeListIterator<ListType> current = headCursor;
    //while current is not NULL
    while (*current != NULL) {
        //set the next as the current next
        FedeListIterator<ListType> next = current;
        next++;
        //delete the current
        delete *current;
        //set the current as next
        current = next;
    }
    
}

template <class ListType>
void FedeList<ListType>::init(){
    //set all cursors to NULL
    headCursor = tailCursor = cursor = FedeListIterator<ListType>();
    //set the size of the list as 0
    listSize = 0;
}


template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_front(ListType element){
    //if head cursor is not NULL (not empty list)
    if (*headCursor != NULL) {
        //create the node to add with the given element and the current head as next
        NodePointer toAdd = new Node<ListType>(element, NULL, *(headCursor));
        //set the node to add as the previous of the current head node
        headCursor->setPrev(toAdd);
        //set the node to add as the head cursor
        headCursor.setNode(toAdd, 0);
        //leave the curso where it is
        //increase the cursor position
        cursor.setPosition(cursor.getPosition() + 1);
        tailCursor.setPosition(tailCursor.getPosition() + 1);
    }
    //else (empty list)
    else {
        //create the node to add with the given element and save it in head cursor
        headCursor.setNode(new Node<ListType>(element), 0);
        //set the tail as the head
        tailCursor = cursor = headCursor;
    }
    //increase the list size
    listSize++;
    //return this list for method chaining
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_back(ListType element){
    //if tail cursor is not NULL
    if (*tailCursor != NULL) {
        //create the node to add with the given element and the current tail as prev
        NodePointer toAdd = new Node<ListType>(element, *tailCursor, NULL);
        //set the node to add as the next of the current tail node
        tailCursor -> setNext(toAdd);
        //set the node to add as the tail cursor and set the position of tail as the listSize
        tailCursor.setNode(toAdd, listSize);
    }
    //else (empty list)
    else {
        //create the node to add with the given element and save it in tail cursor
        tailCursor.setNode(new Node<ListType>(element), listSize);
        //set the head as the tail
        headCursor = cursor = tailCursor;
    }
    //increase the list size
    listSize++;
    //return this list for method chaining
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::insert(ListType element, int position){
    //if the position is between 0 and the size of the list (internal))
    if ((position > 0) && (position < listSize)){
        //move the cursor over the position
        moveCursor(position);
        //create a new node with the given element, the previous and the current (future next) node
        NodePointer nodeToInsert = new Node<ListType>(element, cursor->getPrev(), *cursor);
        //set the node to insert as the next of the previous
        cursor -> getPrev() -> setNext(nodeToInsert);
        //set the node to insert as the previous
        cursor -> setPrev(nodeToInsert);
        //increase the cursor position
        cursor.setPosition(cursor.getPosition() + 1);
        //increase the tailcursor position
        tailCursor.setPosition(tailCursor.getPosition() + 1);
        //increase the list size
        listSize++;
    }
    //else if the position is 0
    else if(position == 0){
        //push front
        push_front(element);
    }
    //else if the position is listsize (wanna append)
    else if(position == listSize){
        //push back
        push_back(element);
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
    //return this list for method chaining
    return (this);
};

template <class ListType>
ListType FedeList<ListType>::pop_front(){
    //the result
    ListType result;
    //if there is at least 1 element (listSize > 0)
    if (listSize > 0){
        //save the result value
        result = headCursor -> getValue();
        //save the node to delete
        NodePointer toDelete = *headCursor;
        //if there is more than 1 element
        if (listSize > 1){
            //if the cursor is pointing to the head
            if(cursor == headCursor){
                //move the cursor to the future head
                cursor.setNode(cursor->getNext(), cursor.getPosition());
                //do not change cursor position
            }
            //else (the cursor is ahead)
            else{
                //decrease the cursor position
                cursor.setPosition(cursor.getPosition() - 1);
            }
            //decrease the tailcursor position
            tailCursor.setPosition(tailCursor.getPosition() - 1);
            //set head cursor as the next of the current head cursor
            headCursor.setNode(headCursor->getNext(), headCursor.getPosition());
            //set the previous of the head cursor as NULL
            headCursor -> setPrev(NULL);
        } 
        //else (only one element)
        else {
            //set head cursor, cursor and tail cursor as NULL
            cursor.setNode(NULL, -1);
            headCursor = tailCursor = cursor;
            //set the cursor position as -1 (empty list)
            cursor.setPosition(-1);
        }
        //delete the node to delete
        delete toDelete;
        //decrease the list size
        listSize--;
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("the list is empty"));
    }
    //return the result
    return result;
}

template <class ListType>
ListType FedeList<ListType>::pop_back(){
    //the result
    ListType result;
    //if there is at least 1 element (listSize > 0)
    if (listSize > 0){
        //if the cursor is pointing to the tail
        if(cursor == tailCursor){
            //move the cursor to the future tail
            cursor--;
        }
        //else (the cursor is behind): do nothing
        //save the result value
        result = tailCursor -> getValue();
        //save the node to delete
        NodePointer toDelete = *tailCursor;
        //if there is more than 1 element
        if (listSize > 1){
            //set tail cursor as the previous of the current tail cursor
            tailCursor.setNode(tailCursor->getPrev(), tailCursor.getPosition());
            //set the next of the tail cursor as NULL
            tailCursor -> setNext(NULL);
        }
        //else (only one element)
        else {
            //set head cursor, tail cursor and cursor as NULL
            cursor.setNode(NULL, -1);
            headCursor = tailCursor = cursor;
            //cursor position is already set as -1
        }
        //delete the node to delete
        delete toDelete;
        //decrease the list size
        listSize--;
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("the list is empty"));
    }
    //return the result
    return result;
}

template <class ListType>
ListType FedeList<ListType>::get(int position){
    //move the cursor to the position if exists. It throws an exception otherwise.
    moveCursor(position);
    //return the value in the given position
    return cursor -> getValue();
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::remove(int position){
    //if the position is valid
    if (isValidPosition(position)){
        //if the given position is 0 (first element)
        if (position == 0){
            //pop from the front
            pop_front();
        }
        //else if the position is listSize - 1 (last element)
        else if (position == (listSize - 1)){
            //pop from the back
            pop_back();
        }
        //else (internal position)
        else {
            //move the cursor to the position
            moveCursor(position);
            //the node to delete
            NodePointer toDelete = *cursor;
            //---- bypass the node to delete ----
            //save the previous
            NodePointer previus = toDelete -> getPrev();
            //save the next
            NodePointer next = toDelete -> getNext();
            //set the next of previous as next
            previus -> setNext(next);
            //set the previous of next as previous
            next -> setPrev(previus);
            //---- end bypass ----
            //set the cursor as next (should not be nullbecause is checked if it is or not the last element)
            //(can't use moveCursor because cursorPosition must remain the same)
            cursor.setNode(next, cursor.getPosition());
            //decrease tailcursor position
            tailCursor.setPosition(tailCursor.getPosition() - 1);
            //delete the node to delete
            delete toDelete;
            //decrease the list size
            listSize--;
        }
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
    //return this list for method chaining
    return (this);
}

template<class ListType>
FedeList<ListType>* FedeList<ListType>::removeByElement(ListType element){
    //int counter set as 0
    int i = 0;
    //found element? default: false
    bool found = false;
    //while not found and the counter is less than the list size
    while ((!found) && (i<listSize)){
        //move the cursor to the i position
        moveCursor(i);
        //if the value in the pointed node is equal to the searched element
        if (cursor -> getValue() == element){
            //set the found as true
            found = true;
        } 
        //else
        else{
            //increase the counter
            i++;
        }
    }
    //if the ites has been found
    if(found){
        //remove the element
        remove(i);
    }
    //return this list for method chaining
    return (this);
}


template <class ListType>
int FedeList<ListType>::getSize() const{
    //return the list size
    return listSize;
};

template <class ListType>
void FedeList<ListType>::prepareSearch(int position){
    //compute the distance between the current cursor position and the searched position
    int cursorDistance = abs(cursor.getPosition() - position);
    //the distance position-head is position
    int headDistance = position;
    //the distance position-head is position
    int tailDistance = (listSize - 1 - position);
    //if the distance between the position to get and the head/tail is less thant the distance
    //between cursor and position we can make an optimization.
    if ((headDistance < cursorDistance) || (tailDistance < cursorDistance)){
        //if head distance is less than tail distance
        if (headDistance <= tailDistance){
            //set the cursor as the head
            cursor = headCursor;
        }
        //else if tail distance is less than head distance
        else {
            //set the cursor as the tail
            cursor = tailCursor;
        }
    }
}

template<class ListType>
void FedeList<ListType>::moveCursor(int position){
    //if the position is valid
    if (isValidPosition(position)){
        //prepare to search
        prepareSearch(position);
        cursor[position];
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
}

template<class ListType>
bool FedeList<ListType>::isValidPosition(int position){
    //check and return if the position is between and listize-1 (if the size is zero it will always return false)
    return ((position >= 0) && (position <= (listSize - 1)));
}

template<class ListType>
void FedeList<ListType>::sort() {
    //declare a constant temporary variable for the list size
    const int size = this->listSize;
    //declare i and j for indexes of the cycles
    int i, j;
    //declare a variabile for swapping values
    ListType tmp;
    //for the list size times
    for (i = 0; i < size; i++) {
        //for the list size -1 - i times
        for (j = 0; j < size - 1 - i; j++) {
            //if the current value is greater than its successor
            if (this->get(j) > this->get(j + 1)) {
                //swap the values
                //by saving in the temp variable the value of node  in positon j
                tmp = this->get(j);
                //TODO creare a set method for don't do the remove+insert operations
                //remove the node in position j
                this->remove(j);
                //duplicate the node in position j (the old node in postion j+1)
                this->insert(this->get(j), j);
                //remove the node in position j+1
                this->remove(j + 1);
                //insert the value of the old node in position j in position j+1
                this->insert(tmp, j + 1);
            }
        }
    }
}

#endif	/* FEDELIST_CPP */