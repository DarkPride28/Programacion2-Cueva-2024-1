
/* 
 * File:   Promociones.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:38 AM
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H

#include "Lista.h"


class Promociones {
public:
    Promociones();
    Promociones(const Promociones& orig);
    virtual ~Promociones();
    void leepedido();
    void actualizapedidos();
    void imprimepedidos();
private:
    Lista Lpedidos;
};

#endif /* PROMOCIONES_H */

