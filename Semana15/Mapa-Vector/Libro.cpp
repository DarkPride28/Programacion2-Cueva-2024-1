/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: cueva
 * 
 * Created on 10 de junio de 2024, 10:37 PM
 */
#include <iostream>
#include <cstring>
#include "Libro.h"

using namespace std;

Libro::Libro() {
    nombre=nullptr;
    paginas=0;
    peso=0;

}

Libro::Libro(const Libro& orig) {
    nombre=nullptr; // debe ir obligatorio
    *this=orig;
}

void Libro::operator =(const Libro&aux){
    char cad[100];
    
    aux.GetNombre(cad);
    SetNombre(cad);
    paginas = aux.paginas;
    peso = aux.peso;
    
}

Libro::~Libro() {
    if(nombre!=nullptr)
        delete nombre;
}

void Libro::SetNombre(char*cad){
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libro::GetNombre(char* cad)const{
    if(nombre!=nullptr)
        strcpy(cad,nombre);
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

/*
N,Diamantes y pedernales,120,0.4,Jose Maria Arguedas
N,El otonio del patriarca,105,0.5,Gabriel Garcia Marquez
N,El viejo y el mar,110,0.4,Hernest Hemingway
 
 */
void Libro::lee(ifstream &arch){
    char cad[100],c;
    
    arch.getline(cad,100,',');
    SetNombre(cad);
    arch >> paginas >> c >> peso;
    arch.get();
    
    
}

void Libro::imprime(ofstream&arch){
    
    arch <<"Titulo:"<< nombre << endl;
    arch << "Peso: " << peso << endl;
    
}

