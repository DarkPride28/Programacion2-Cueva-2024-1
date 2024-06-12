/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteC.cpp
 * Author: cueva.r
 * 
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#include "ClienteC.h"

ClienteC::ClienteC() {
    flete=0;
}

ClienteC::ClienteC(const ClienteC& orig) {
}

ClienteC::~ClienteC() {
}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::lee(ifstream&arch){
    arch >> flete;
    arch.get();
    
    Cliente::lee(arch);
    
}

void ClienteC::imprime(ofstream&arch){
    Cliente::imprime(arch);
    
    arch << "Flete: " << flete << endl;
}