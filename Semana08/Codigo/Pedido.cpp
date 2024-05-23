/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: cueva.r
 * 
 * Created on 7 de mayo de 2024, 10:55 AM
 */
#include <iostream>
#include <cstring>
#include "Pedido.h"

using namespace std;


Pedido::Pedido() {
    codigo=0;
    nombre=nullptr;
    cantidad=0;
    precio=0;
    dni=0;
    fecha=0;
       
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}


void Pedido::SetNombre(char*cad){
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Pedido::GetNombre(char* cad)const{
    if(nombre!=nullptr)
        strcpy(cad,nombre);
}
/*
118050,PAPAYA,11,11,81114108,09/03/2020
126218,TANJERINA,11,5.5,33713901,26/01/2020
 */
ifstream &operator >> (ifstream &arch,Pedido &ped){
    int codigo,dni,cant,fecha,dd,mm,aa;
    char nom[100],c;
    double precio;
    
    arch >> codigo;
    if(!arch.eof()){
        arch.get();
        arch.getline(nom,100,',');
        arch >> cant>>c>>precio>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
        fecha=aa*10000+mm*100+dd;
        ped.SetCodigo(codigo);
        ped.SetNombre(nom);
        ped.SetCantidad(cant);
        ped.SetPrecio(precio);
        ped.SetDni(dni);
        ped.SetFecha(fecha);
    }
    return arch;
}