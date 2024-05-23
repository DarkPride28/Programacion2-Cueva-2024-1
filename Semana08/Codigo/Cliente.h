/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: cueva.r
 *
 * Created on 7 de mayo de 2024, 10:54 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
#include "Pedido.h"

using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumped(int numped);
    int GetNumped() const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(char*);
    void GetNombre(char*)const;
    void imprimepedido(ofstream &);
    void operator = (Pedido &); //Pasando por referencia
                                // para no usar el const copiar
    void operator -=(Pedido &);
    
private:
    int dni;
    char categoria;
    char *nombre;
    int numped;
    double total;
    Pedido lped[100];

};
//No son metodos
ifstream &operator >> (ifstream&,Cliente&);
ofstream &operator << (ofstream&,Cliente&);

#endif /* CLIENTE_H */

