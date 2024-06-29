/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.cpp
 * Author: cueva
 * 
 * Created on 12 de junio de 2024, 10:38 PM
 */
#include <iostream>
#include <cstring>
#include "Revista.h"

using namespace std;

Revista::Revista() {
    anho=0;
    numero=0;
    vigencia=1;
    
}

Revista::Revista(const Revista& orig) {

}

Revista::~Revista() {
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}


/*R,Educacion,48,0.18,10199403,2022,3
R,Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
R,Boletin de Arqueologia PUCP,45,0.25,10292004,2023,2
 */
void Revista::lee(ifstream&arch){
    char c;
    Libro::lee(arch);
    getline(arch,ISSN,',');
    arch >> anho >> c >> numero;
    arch.get();
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::actualiza(){
    if(anho<2020)
        vigencia=0;
}
void Revista::imprime(ofstream&arch){
    Libro::imprime(arch);
    arch << "ISSN:" <<  ISSN <<"    Año: " << anho << "     Vigencia: "<<vigencia <<endl<<endl;
    
}

void Revista::SetISSN(string ISSN) {
    this->ISSN = ISSN;
}

string Revista::GetISSN() const {
    return ISSN;
}
