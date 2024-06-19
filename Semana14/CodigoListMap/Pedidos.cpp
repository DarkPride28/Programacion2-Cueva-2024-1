/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedidos.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:15 AM
 */

#include <cstring>
#include <iostream>
#include <iomanip>
#include "Pedidos.h"

using namespace std;

Pedidos::Pedidos() {
    codigo=0;
    nombre=nullptr;
    cantidad=0;
    dni=0;
    fecha=0;
    total=0;
}

Pedidos::Pedidos(const Pedidos& orig) {
}

Pedidos::~Pedidos() {
    delete nombre;
}

void Pedidos::SetTotal(double total) {
    this->total = total;
}

double Pedidos::GetTotal() const {
    return total;
}

void Pedidos::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedidos::GetFecha() const {
    return fecha;
}

void Pedidos::SetDni(int dni) {
    this->dni = dni;
}

int Pedidos::GetDni() const {
    return dni;
}

void Pedidos::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedidos::GetCantidad() const {
    return cantidad;
}

void Pedidos::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedidos::GetCodigo() const {
    return codigo;
}

void Pedidos::SetNombre(char*cad){
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Pedidos::GetNombre(char* cad)const{
    if(nombre!=nullptr)
        strcpy(cad,nombre);
}

void Pedidos::lee(int cod,ifstream& arch){
    char nombre[100],c;
    int  dni,stock,fecha,dd,mm,aa;
    double total;
    
    arch.get();
    SetCodigo(cod);
    arch.getline(nombre,100,',');
    SetNombre(nombre);
    arch >> stock;
    arch.get();
    SetCantidad(stock);
    arch >> total;
    SetTotal(total);
    arch.get();
    arch >> dni;
    SetDni(dni);
    arch.get();
    arch >> dd >>c>>mm>>c>>aa;
    arch.get();
    fecha=aa*10000+mm*100+dd;
    SetFecha(fecha);
 }

void Pedidos::imprime(ofstream &arch,double desc,double fle){
    char cad[100];
    double monto;
    
    arch<<endl<<left <<setw(10)<<GetFecha()<<endl;
    GetNombre(cad);
    arch <<setw(10)<<codigo<<setw(50)<< cad <<endl;
    arch<<"DNI: "<< dni << endl;
    arch <<"Monto Total: "<<right<<setprecision(2)<<fixed;
    monto = GetTotal()+(GetTotal()*fle/100)-(GetTotal()*desc/100);
    arch <<setw(10)<< monto <<endl;
}