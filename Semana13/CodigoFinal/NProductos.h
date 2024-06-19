/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.h
 * Author: cueva.r
 *
 * Created on 12 de junio de 2024, 11:02 AM
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include <fstream>
#include "Producto.h"

using namespace std;

class NProductos {
public:
    NProductos();
    NProductos(const NProductos& orig);
    virtual ~NProductos();
    void leeproductos(ifstream &);
    void imprimeproductos(ofstream &);
private:
    Producto *prod;
};

#endif /* NPRODUCTOS_H */

