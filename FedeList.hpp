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
 */
template <class ListType> 
class FedeList {
    FedeList() throw (exception);
    FedeList(ListType element);
    FedeList(const FedeList& orig) throw (exception);
    virtual ~FedeList(); 
    FedeList* push_front(ListType element)  throw (exception);
    ListType get(int position) throw (exception);
    ListType get(ListType element) throw (exception);
    FedeList* remove(int position)  throw (exception);    
    FedeList* remove(ListType element)  throw (exception); 
protected:
    typedef Node<ListType>* NodePointer;
    NodePointer headCursor;
    NodePointer tailCursor;
    NodePointer cursor;
    int cursorPosition;
    int listLength;
   // void prepareSearch(int posizione) throw (exception);
   // NodePointer search(int posizione);
};

#endif	/* FEDELIST_H */

