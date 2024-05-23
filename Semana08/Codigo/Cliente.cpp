/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: cueva.r
 * 
 * Created on 7 de mayo de 2024, 10:54 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() {
    dni=0;
    nombre=nullptr;
    numped=0;
    total=0;
}

Cliente::Cliente(const Cliente& orig) {
    cout << "Hola soy el copia" <<endl;

}


Cliente::~Cliente() {

}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumped(int numped) {
    this->numped = numped;
}

int Cliente::GetNumped() const {
    return numped;
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
/*
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
 */
void Cliente::imprimepedido(ofstream&arch){
    char nombre[100];
    
    for(int i=0;lped[i].GetDni()!=0;i++){
        lped[i].GetNombre(nombre);
        arch << setw(10)<< lped[i].GetFecha() << setw(10) << lped[i].GetCodigo();
        arch << setw(80) << nombre << setw(10) << lped[i].GetCantidad();
        arch << setprecision(2) << fixed << setw(10) << lped[i].GetPrecio()<< endl;
    }
    
}


void Cliente::operator =(Pedido&ped){
    int n;
    char cad[100];
    n=GetNumped();
    lped[n].SetCodigo(ped.GetCodigo());
    lped[n].SetCantidad(ped.GetCantidad());
    lped[n].SetFecha(ped.GetFecha());
    lped[n].SetPrecio(ped.GetPrecio());
    lped[n].SetDni(ped.GetDni());
    ped.GetNombre(cad);
    lped[n].SetNombre(cad);
    numped++;
    total+=ped.GetPrecio();
}

void
void Cliente::operator-=(Pedido &ped) {
    
    
}


/*
71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO,A
29847168,ALDAVE ZEVALLOS ROSARIO,A
 */

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
/*  int dni;
    char categoria;
    char *nombre;
    int numped;
    double total;
    Pedido lped[100];
 */
ofstream &operator << (ofstream &arch,Cliente &clie){
    char nombre[100];
    
    clie.GetNombre(nombre);
    arch <<setw(10)<< clie.GetDni() << setw(80) << nombre << endl ;
    clie.imprimepedido(arch);
    
}