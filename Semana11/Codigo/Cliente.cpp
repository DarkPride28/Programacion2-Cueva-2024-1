/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: cueva.r
 * 
 * Created on 22 de mayo de 2024, 10:15 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cliente.h"

Cliente::Cliente() {
    dni = 0;
    nombre=nullptr;
    cantped = 0;
    totalped = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetNombre(char*cad){
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Cliente::GetNombre(char* cad)const{
    if(nombre!=nullptr)
        strcpy(cad,nombre);
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::lee(ifstream&arch){
    char nom[100];
    
    arch >> dni;
    arch.get();
    arch.getline(nom,100);
    SetNombre(nom);
}

void Cliente::imprime(ofstream&arch){
    char nom[100];
    
    GetNombre(nom);
    arch << endl<<setw(10) << dni << setw(50) << nom << endl;
}


ifstream &operator >> (ifstream &arch,Cliente &cli){
    int dni;
    char nom[100],cat;
    
    arch >> dni;
    if(!arch.eof()){
        arch.get();
        arch.getline(nom,100,',');
        arch >> cat;
        
        cli.SetDni(dni);
        cli.SetNombre(nom);
        cli.SetCategoria(cat);
    }
    return arch;
}