/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: cueva.r
 *
 * Created on 8 de mayo de 2024, 10:56 AM
 */
#include "Cliente.h"

#ifndef FUNCIONES_H
#define FUNCIONES_H

    void leeclientes(Cliente *lcliente);
    void leepedidos(Pedido *pedidos);
    void cargapedidos(Cliente *clientes,Pedido *pedidos);
    void imprimeclientes(Cliente *clientes);
#endif /* FUNCIONES_H */
