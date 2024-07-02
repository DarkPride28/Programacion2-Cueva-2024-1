/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: cueva
 *
 * Created on 29 de junio de 2024, 05:12 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <map>
#include <vector>
#include "Revista.h"
#include "Estante.h"


class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
    void cargaestante();
    void cargalibros();
    void muestralibros();
private:
    //   ISSN   
    map<string,Revista> mrevista;
    //H,1,20
    map<Estante,vector<Libro>> mestante;
};

#endif /* PROCESA_H */

