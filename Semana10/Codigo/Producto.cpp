/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: cueva.r
 * 
 * Created on 22 de mayo de 2024, 10:23 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    codprod=0;
    nombre=nullptr;
    precio=0;
    stock=0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::SetNombre(char*cad){
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Producto::GetNombre(char* cad)const{
    if(nombre!=nullptr)
        strcpy(cad,nombre);
}

bool Producto::verificadescuento(int cant){
    
    if(codprod/100000==4 and stock>=cant)
        return true;
    return false;
}


/*
459032,GELATINA DANY LIMON 125GR,5.38,24
422763,GALLETAS SUAVICREMAS FRESA 158GR,13.85,14
 */

void Producto::cargaproducto(int codigo){
    int cod,stock;
    double precio;
    char cad[100],temp[500],c;
    
    ifstream arch("productos3.csv",ios::in);
    if(!arch){
        cout << "No se puede leer productos";
        exit(1);
    }
    while(1){
        arch >> cod;
        if(arch.eof()) break;
        if(codigo==cod){
            arch.get();
            arch.getline(cad,100,',');
            arch >> precio >> c >> stock;
            SetPrecio(precio);
            SetCodprod(cod);
            SetStock(stock);
            SetNombre(cad);
            break;
        }
        else
            arch.getline(temp,500);     
    }
}