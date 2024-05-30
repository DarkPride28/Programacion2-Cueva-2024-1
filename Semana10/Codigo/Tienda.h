/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.h
 * Author: cueva.r
 *
 * Created on 22 de mayo de 2024, 10:44 AM
 */

#ifndef TIENDA_H
#define TIENDA_H

#include "Pedido.h"
#include "Cliente.h"


class Tienda {
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga();
    void actualiza(int);
    void muestra();
private:
    Pedido lpedidos[200];
    Cliente lclientes[100];     
    void cargaclientes();
    char buscatipo(int);
};

#endif /* TIENDA_H */

