/* 
 * File:   Nodo.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:24 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedidos.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    int cmp(Nodo &nuevo);
    friend class Lista;
private:
    Pedidos *ped;
    Nodo*sig;
    Nodo*ant;
};

#endif /* NODO_H */

