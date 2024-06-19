
/* 
 * File:   Nodo.h
 * Author: cueva.r
 *
 * Created on 18 de junio de 2024, 11:36 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
#include "Pedidos.h"

using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void reserva(int codigo);
    void leer(int,ifstream&);
    void imprimir(ofstream&);
    bool operator <(const Nodo&);
private:
    Pedidos *ped;
};

#endif /* NODO_H */

