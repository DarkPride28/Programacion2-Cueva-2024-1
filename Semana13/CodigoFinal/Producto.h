/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: cueva.r
 *
 * Created on 12 de junio de 2024, 10:52 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>

using namespace std;

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void SetNombre(char*);
    void GetNombre(char*)const;
    virtual void leeprod(ifstream&);
    virtual void imprimeprod(ofstream&);
private:
    int codprod;
    char *nombre;
    int stock;

};

#endif /* PRODUCTO_H */

