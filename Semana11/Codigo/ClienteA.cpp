/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteA.cpp
 * Author: cueva.r
 * 
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#include "ClienteA.h"

ClienteA::ClienteA() {
    descuento=0;
}

ClienteA::ClienteA(const ClienteA& orig) {
}

ClienteA::~ClienteA() {
}

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::lee(ifstream&arch){
    arch >> descuento;
    arch.get();
    // llamando al padre
    Cliente::lee(arch);
}

void ClienteA::imprime(ofstream&arch){
    Cliente::imprime(arch);
    
    arch << "Descuento: " << descuento << endl;
}