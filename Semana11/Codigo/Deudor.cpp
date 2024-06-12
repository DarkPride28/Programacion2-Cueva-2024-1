/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deudor.cpp
 * Author: cueva.r
 * 
 * Created on 29 de mayo de 2024, 11:32 AM
 */

#include "Deudor.h"
#include "ClienteA.h"
#include "ClienteC.h"
#include "ClienteB.h"

Deudor::Deudor() {
    Cdeudor=nullptr;
}

Deudor::Deudor(const Deudor& orig) {
}

Deudor::~Deudor() {
}
/*
A,25,71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO
A,25,29847168,ALDAVE ZEVALLOS ROSARIO
C,10,79475585,RETTO ARCA ANNIE MAGDA
C,10,91897732,GAMARRA ALCOCER VIRGINIA
C,10,33397650,RONDON EGUSQUIZA CARMELA VALENTINA
B,10,5,83236386,RIVERO CORRALES JUAN FERNANDO
 */
void Deudor::leedeudor(ifstream &arch){
    char tipo;
   
    arch >> tipo;
    if(!arch.eof()){
        arch.get();
        if(tipo=='A')
            Cdeudor = new ClienteA;
        if(tipo=='B')
            Cdeudor = new ClienteB;        
        if(tipo=='C')
            Cdeudor = new ClienteC;        
        Cdeudor->lee(arch);
    }
}

bool Deudor::existe(){
    if(Cdeudor==nullptr)
        return false;
    return true;        
}

void Deudor::imprimedeudor(ofstream&arch){
    Cdeudor->imprime(arch);
    
}