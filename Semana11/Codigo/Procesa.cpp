/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: cueva.r
 * 
 * Created on 29 de mayo de 2024, 11:26 AM
 */

#include <fstream>
#include <iostream>
#include "Procesa.h"

using namespace std;
Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::carga(){
    int i=0;
    ifstream arch("clientes3.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo cliente";
        exit(1);
    }
    while(1){
        ldeudor[i].leedeudor(arch);
        if(arch.eof()) break;
        i++;
    }
    
}

void Procesa::muestra(){
    int i=0;
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo reporte";
        exit(1);
    }   
    for(int i=0;ldeudor[i].existe();i++){
        ldeudor[i].imprimedeudor(arch);       
    }
    
}
