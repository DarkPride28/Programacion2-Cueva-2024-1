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
#include "PedidoEspecial.h"
#include "PedidoUsual.h"
#include "PedidoEventual.h"

using namespace std;

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::reserva(int codigo, Pedidos*&ped){
    
    if(codigo<400000)
        ped = new PedidoEspecial;
    if(codigo>=400000 and codigo<600000)
        ped = new PedidoUsual;
    if(codigo>=600000)
        ped= new PedidoEventual;
    
}

void Procesa::carga(){
    Pedidos *ped;
    int codigo;
    
    ifstream arch("pedidos5.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo pedidos";
        exit(1);
    }
    while(1){
        arch >> codigo; 
        if(arch.eof()) break;
        reserva(codigo,ped);
        ped->lee(codigo,arch);
        lped.push_back(ped);
        
    }    
    
    
}

void Procesa::muestra(){
    
    ofstream arch("reporte.txt",ios::out);
    if(!arch)
    {   cout << "Archivo no encontrado" << endl;
        exit(1);
    }
    for(list<Pedidos*>::iterator it=lped.begin();
            it!=lped.end();it++ ){
        (*it)->imprime(arch,0,0);   
//        Pedidos*ped;
//        ped=*it;
//        ped->imprime(arch,0,0);
    }
}