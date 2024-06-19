/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:23 AM
 */

#include "PedidoEventual.h"

PedidoEventual::PedidoEventual() {
}

PedidoEventual::PedidoEventual(const PedidoEventual& orig) {
}

PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::lee(int cod, ifstream &arch){
    
    arch.get();
    arch >> flete;
    Pedidos::lee(cod,arch);
}

void PedidoEventual::setFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::getFlete() const {
    return flete;
}

void PedidoEventual::actualiza(){
    flete=0;
} 

void PedidoEventual::imprime(ofstream& arch,double a, double b){
    Pedidos::imprime(arch,0,flete);
    arch << "Flete : " << flete<< endl;;
    
}