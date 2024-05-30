/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: cueva.r
 * 
 * Created on 22 de mayo de 2024, 10:27 AM
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Pedido.h"

using namespace std;

Pedido::Pedido() {
    codigo=0;
    cantidad=0;
    dni=0;
    fecha=0;
    total=0;
    obs=nullptr;
    
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
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
void Pedido::SetObs(char*cad){
    if(obs!=nullptr) delete obs;
    obs = new char[strlen(cad)+1];
    strcpy(obs,cad);
}

void Pedido::GetObs(char* cad)const{
    if(obs!=nullptr)
        strcpy(cad,obs);
}

void Pedido::actualizadescuento(char tipo){
    
    if(tipo=='A'){
        total*=0.5;
        SetObs("Descuento Especial del 50%");
    }
    if(tipo=='B'){
        total*=0.7;
        SetObs("Descuento Especial del 30%");
    }
    if(tipo=='C'){
        total*=0.9;
        SetObs("Descuento Especial del 10%");
    }
}


/*
118050,8,79475585,16/12/2019
118050,5,79475585,30/04/2020
 */
ifstream &operator >> (ifstream &arch,Pedido&ped){
    int codigo,cant,dni,dd,mm,aa,fecha;
    char c;
    
    arch >> codigo;
    if(!arch.eof()){
        arch >> c >> cant >> c >> dni >> c >> dd >> c >> mm >>c >> aa; 
        fecha = aa*10000+mm*100+dd;
        ped.SetCantidad(cant);
        ped.SetCodigo(codigo);
        ped.SetDni(dni);
        ped.SetFecha(fecha);
        //aqui voy a leer
        ped.cargaproducto(codigo);
        ped.SetTotal(cant*ped.GetPrecio());
        ped.SetObs(" ");
    }
    return arch;
    
}

ofstream &operator <<(ofstream &arch,Pedido &ped){
    char nom[100],obs1[100];
    
    arch << setw(20)<< ped.GetFecha() << setw(10) << ped.GetCodigo();
    ped.GetNombre(nom);
    arch << setw(50) << nom << setw(5) << ped.GetCantidad();
    arch << setprecision(2) << fixed << setw(10) << ped.GetPrecio();
    arch << setw(10) << ped.GetTotal();
    ped.GetObs(obs1);
    arch << setw(50) << obs1;
    
    return arch;
}