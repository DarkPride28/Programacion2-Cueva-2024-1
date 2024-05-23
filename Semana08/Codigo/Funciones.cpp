/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: cueva.r
 * 
 * Created on 8 de mayo de 2024, 10:56 AM
 */
#include <fstream>
#include <iostream>
#include "Funciones.h"
#include "Cliente.h"

using namespace std;

void leeclientes(Cliente *lcliente){
    int i=0;
    ifstream arch("clientes2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo clientes"<<endl;
        exit(1);
    }
    while(1){
        arch >> lcliente[i];
        if(arch.eof())break;
        i++;
    }
    
}

void leepedidos(Pedido *lpedidos){
    int i=0;
    ifstream arch("pedidos2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo pedidos"<<endl;
        exit(1);
    }
    while(1){
        arch >> lpedidos[i];
        if(arch.eof())break;
        i++;
    }    
    
}

void cargapedidos(Cliente *clientes,Pedido *pedidos){
    
    for(int i=0;clientes[i].GetDni()!=0;i++){
        for(int j=0;pedidos[j].GetCodigo()!=0;j++)
            if(clientes[i].GetDni()==pedidos[j].GetDni())
                clientes[i]=pedidos[j];
        
    }
    
}

void imprimeclientes(Cliente *clientes){
    
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout <<  "No se puede imprimir";
        exit(1);
    }
    for(int i=0;clientes[i].GetDni()!=0;i++){
        arch << clientes[i];
        arch << endl;
    }
}
