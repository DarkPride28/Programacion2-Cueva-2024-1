/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedidos.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:15 AM
 */

#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <fstream>

using namespace std;
class Pedidos {
public:
    Pedidos();
    Pedidos(const Pedidos& orig);
    virtual ~Pedidos();
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
    void SetNombre(char*);
    void GetNombre(char*)const;
    virtual void lee(int cod,ifstream& arch);
    virtual void actualiza()=0; //Yo soy puro 
    virtual void imprime(ofstream &,double ,double );
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

#endif /* PEDIDOS_H */

