/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteB.cpp
 * Author: cueva.r
 * 
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#include "ClienteB.h"

ClienteB::ClienteB() {
    descuento=0;
    flete=0;
}

ClienteB::ClienteB(const ClienteB& orig) {
}

ClienteB::~ClienteB() {
}

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}

void ClienteB::lee(ifstream&arch){
    char c;
    
    arch >> descuento >> c >> flete >> c;
    Cliente::lee(arch);
    
}

void ClienteB::imprime(ofstream&arch){
    Cliente::imprime(arch);
    
    arch << "Descuento: " << descuento << endl;
    arch << "Flete: " << flete << endl;
}