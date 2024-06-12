/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteB.h
 * Author: cueva.r
 *
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H

#include "Cliente.h"


class ClienteB:public Cliente {
public:
    ClienteB();
    ClienteB(const ClienteB& orig);
    virtual ~ClienteB();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    double descuento;
    double flete;
};

#endif /* CLIENTEB_H */

