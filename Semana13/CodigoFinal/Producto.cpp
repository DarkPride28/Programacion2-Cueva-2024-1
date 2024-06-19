/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: cueva.r
 * 
 * Created on 12 de junio de 2024, 10:52 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Producto.h"

Producto::Producto() {
    codprod = 0;
    nombre = nullptr;
    stock = 0;
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

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::SetNombre(char*cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Producto::GetNombre(char* cad)const {
    if (nombre != nullptr)
        strcpy(cad, nombre);
}

void Producto::leeprod(ifstream &arch) {
    arch >> codprod;
    if (arch.eof())return;
    arch.get();
    char cadena[120];
    arch.getline(cadena, 120, ',');
    SetNombre(cadena);
    arch >> stock;
    arch.get();
}

void Producto::imprimeprod(ofstream &arch) {

    arch << setw(10) << codprod << setw(50) << nombre <<
            setw(10) << stock << endl;
}
