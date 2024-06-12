/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoUsual.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:23 AM
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H

#include "Pedidos.h"


class PedidoUsual: public Pedidos{
public:
    PedidoUsual();
    PedidoUsual(const PedidoUsual& orig);
    virtual ~PedidoUsual();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(int , ifstream & );
    void actualiza();
    void imprime(ofstream&arch,double a,double b);
private:
    double flete;
    double descuento;
};

#endif /* PEDIDOUSUAL_H */

