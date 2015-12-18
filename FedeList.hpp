/* 
 * File:   FedeList.h
 * Author: fede
 *
 * Created on 16 novembre 2015, 19.01
 */

#ifndef FEDELIST_H
#define	FEDELIST_H

#include <cstring>
#include <exception>

using namespace std;

template <class TipoLista> class FedeList {
protected:
    struct Elemento {
        TipoLista valore;
        Elemento* next = NULL;
    };
    typedef Elemento* Epointer;
    Epointer head;
    Epointer cursor;
    Epointer cursorCoda;
    int cursorPosition;
    int lunghezzaLista;
    virtual void prepareSearch(int posizione) throw (exception);
    Epointer search(int posizione);
public:
    FedeList();
    FedeList(const FedeList& orig);
    virtual ~FedeList();
    virtual void add(TipoLista tipolista);
    //ritorna l'elemento della lista in una certa posizione
    virtual TipoLista get(int posizione) throw (exception);
    void remove(Epointer p, int posizione);
};

#endif	/* FEDELIST_H */

