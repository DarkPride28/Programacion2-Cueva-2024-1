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
    *this=orig;
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

void Revista::lee(ifstream&arch){
    char c;
    Libro::lee(arch);
    //arch.getline(cad,100,',');
    getline(arch,ISSN,','); //soy diferente
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

void Revista::operator =(const Revista&orig){
    char cad[100];
    ISSN=orig.ISSN; //soy string
    anho=orig.anho;
    numero=orig.numero;
    vigencia=orig.vigencia;
    
    orig.GetNombre(cad); // No soy string
    SetNombre(cad);
    SetPaginas(orig.GetPaginas());
    SetPeso(orig.GetPeso());
    
}