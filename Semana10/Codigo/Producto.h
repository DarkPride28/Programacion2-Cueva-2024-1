/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: cueva.r
 *
 * Created on 22 de mayo de 2024, 10:23 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void SetNombre(char*);
    void GetNombre(char* cad)const;
    void cargaproducto(int );
    bool verificadescuento(int);
private:
    int codprod;
    char*nombre;
    double precio;
    int stock;
};

#endif /* PRODUCTO_H */

