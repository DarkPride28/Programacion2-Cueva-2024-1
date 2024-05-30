/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: cueva.r
 *
 * Created on 22 de mayo de 2024, 10:27 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <fstream>

using namespace std;

class Pedido:public Producto {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetObs(char*);
    void GetObs(char* cad)const;
    void actualizadescuento(char );
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;
};
ifstream &operator >> (ifstream &,Pedido&);
ofstream &operator << (ofstream &,Pedido&);
#endif /* PEDIDO_H */

