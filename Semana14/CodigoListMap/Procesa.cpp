/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: cueva.r
 * 
 * Created on 18 de junio de 2024, 10:45 AM
 */
#include <iostream>
#include <iterator>
#include "Procesa.h"


using namespace std;

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}



void Procesa::carga(){
    Nodo naux;
    int codigo,i=0;
    
    ifstream arch("pedidos5.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo pedidos";
        exit(1);
    }
    while(1){
        arch >> codigo; 
        if(arch.eof()) break;
        naux.reserva(codigo);
        naux.leer(codigo,arch);
        lped.push_back(naux);
        mped[i] = naux;
        i++;        
    }    
    
    
}

void Procesa::muestra(){
    
    ofstream arch("reporte.txt",ios::out);
    if(!arch)
    {   cout << "Archivo no encontrado" << endl;
        exit(1);
    }
    lped.sort();
    for(list<Nodo>::iterator it=lped.begin();
            it!=lped.end();it++ ){
        it->imprimir(arch);
        
    }
    
    ofstream repo("MapRepo.txt",ios::out);
    if(!repo)
    {   cout << "Archivo no encontrado" << endl;
        exit(1);
    }
    for(map<int,Nodo>::iterator itm=mped.begin();
            itm!=mped.end();itm++){
        repo << itm->first;
        itm->second.imprimir(repo);
    }
    map<int,Nodo>::iterator itm=mped.find(100);
    itm->second.imprimir(repo);
}