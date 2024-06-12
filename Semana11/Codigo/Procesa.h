/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: cueva.r
 *
 * Created on 29 de mayo de 2024, 11:26 AM
 */

#ifndef PROCESA_H
#define PROCESA_H

#include "Deudor.h"


class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
private:
    Deudor ldeudor[50];
};

#endif /* PROCESA_H */

