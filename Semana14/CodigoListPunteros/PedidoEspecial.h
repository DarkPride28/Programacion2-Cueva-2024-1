/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEspecial.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:20 AM
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedidos.h"


class PedidoEspecial:public Pedidos {
public:
    PedidoEspecial();
    PedidoEspecial(const PedidoEspecial& orig);
    virtual ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(int cod, ifstream&arch);
    void actualiza(){};
    void imprime(ofstream& arch,double,double );
private:
    double descuento;
};

#endif /* PEDIDOESPECIAL_H */

