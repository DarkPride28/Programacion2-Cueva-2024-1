/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.cpp
 * Author: cueva.r
 * 
 * Created on 12 de junio de 2024, 11:00 AM
 */
#include <iostream>
#include "Programa.h"

using namespace std;

Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::cargaproductos(){
    NProductos naux;
    ifstream arch("Productos4.csv",ios::in);
    if(!arch){
        cout <<"Pipipi no abre el archivo";
        exit(1);
    }
    while(1){
        naux.leeproductos(arch);
        if(arch.eof()) break;
        vproductos.push_back(naux);
    }
    
}


void Programa::muestraproductos(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout <<"Pipipi no abre el reporte";
        exit(1);
    }    
    for(int i=0;i<vproductos.size();i++){
     vproductos[i].imprimeproductos(arch);
        
    }
    
    
}