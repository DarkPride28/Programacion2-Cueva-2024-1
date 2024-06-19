/* 
 * File:   Programa.h
 * Author: cueva.r
 *
 * Created on 12 de junio de 2024, 11:00 AM
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <vector>
#include "NProductos.h"


class Programa {
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
    void cargaproductos();
    void muestraproductos();
private:
    vector <NProductos> vproductos;
};

#endif /* PROGRAMA_H */

