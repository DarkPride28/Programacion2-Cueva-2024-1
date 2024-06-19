/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEventual.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:23 AM
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H
#include <fstream>
#include "Pedidos.h"

using namespace std;
class PedidoEventual: public Pedidos {
public:
    PedidoEventual();
    PedidoEventual(const PedidoEventual& orig);
    virtual ~PedidoEventual();
    void lee(int , ifstream &);
    void setFlete(double flete);
    double getFlete() const;
    void actualiza();
    void imprime(ofstream& arch,double , double );
private:
    double flete;
};

#endif /* PEDIDOEVENTUAL_H */

