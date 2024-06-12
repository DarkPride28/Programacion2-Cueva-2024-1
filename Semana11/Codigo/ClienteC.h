/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteC.h
 * Author: cueva.r
 *
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H

#include "Cliente.h"


class ClienteC:public Cliente {
public:
    ClienteC();
    ClienteC(const ClienteC& orig);
    virtual ~ClienteC();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    double flete;
};

#endif /* CLIENTEC_H */

