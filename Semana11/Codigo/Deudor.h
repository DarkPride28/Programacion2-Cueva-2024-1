/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deudor.h
 * Author: cueva.r
 *
 * Created on 29 de mayo de 2024, 11:32 AM
 */

#ifndef DEUDOR_H
#define DEUDOR_H

#include "Cliente.h"


class Deudor {
public:
    Deudor();
    Deudor(const Deudor& orig);
    virtual ~Deudor();
    void leedeudor(ifstream&);
    bool existe();
    void imprimedeudor(ofstream&);
private:
    Cliente *Cdeudor;
};

#endif /* DEUDOR_H */

