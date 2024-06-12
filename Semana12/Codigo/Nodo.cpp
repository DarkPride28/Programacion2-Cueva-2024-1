/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:24 AM
 */

#include "Nodo.h"

Nodo::Nodo() {
    ped=nullptr;
    sig=nullptr;
    ant=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

int Nodo::cmp(Nodo &nuevo){

    if(this->ped->GetDni() > nuevo.ped->GetDni())
        return 1;
    if(this->ped->GetDni()== nuevo.ped->GetDni()){
        if(this->ped->GetFecha() > nuevo.ped->GetFecha())
            return 1;
    }    
    return 0;    
}