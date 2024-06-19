/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: cueva.r
 *
 * Created on 18 de junio de 2024, 10:45 AM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <list>
#include <map>
#include <fstream>

#include "Nodo.h"

using namespace std;

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
private:
    list<Nodo> lped;
    map<int,Nodo> mped;
    
};

#endif /* PROCESA_H */

