/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: cueva
 * 
 * Created on 10 de junio de 2024, 10:35 PM
 */
#include <iostream>
#include "Estante.h"

Estante::Estante() {
    id=0;
    capacidad=0;
}

Estante::Estante(const Estante& orig) {
    clase=orig.clase;
    id=orig.id;
    capacidad=orig.capacidad;
    
}

Estante::~Estante() {
}


void Estante::setCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::getCapacidad() const {
    return capacidad;
}

void Estante::setId(int id) {
    this->id = id;
}

int Estante::getId() const {
    return id;
}

void Estante::setClase(char clase) {
    this->clase = clase;
}

char Estante::getClase() const {
    return clase;
}
/*
H,1,20
V,2,10
 */

void Estante::leestante(ifstream&arch){
    char c;

    arch >> clase;
    if(arch.eof()) return;
    arch >> c >> id >> c >> capacidad;
    arch.get();
}



void Estante::imprime(ofstream &arch)const{
    arch <<endl<<endl<< "Id: " << id <<endl;
    if(clase=='V')
        arch << "Tipo: Vertical" << endl;
    else
        arch << "Tipo: Horizontal"<< endl;
    arch << "Capacidad: " <<capacidad<<endl;
    arch <<"Libros Contenidos:" <<endl;
    arch <<"==================" <<endl;

}

bool Estante::operator <(const Estante&aux)const{
    return (id<aux.id);
}

bool Estante::operator ==(const Estante&aux)const{
    return (id==aux.id);
}

