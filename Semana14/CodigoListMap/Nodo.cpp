/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: cueva.r
 * 
 * Created on 18 de junio de 2024, 11:36 AM
 */
#include "PedidoEspecial.h"
#include "PedidoUsual.h"
#include "PedidoEventual.h"
#include "Nodo.h"

Nodo::Nodo() {
    ped=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
    this->ped = orig.ped;
}

Nodo::~Nodo() {
 
}

void Nodo::reserva(int codigo){
    
    if(codigo<400000)
        ped = new PedidoEspecial;
    if(codigo>=400000 and codigo<600000)
        ped = new PedidoUsual;
    if(codigo>=600000)
        ped= new PedidoEventual;
}

void Nodo::leer(int codigo, ifstream&arch){
    ped->lee(codigo,arch);
    
}

void Nodo::imprimir(ofstream&arch){
    ped->imprime(arch,0,0);
}

bool Nodo::operator <(const Nodo&aux){
    return ped->GetDni()> aux.ped->GetDni();
    
}