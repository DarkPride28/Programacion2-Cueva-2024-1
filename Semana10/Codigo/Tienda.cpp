/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.cpp
 * Author: cueva.r
 * 
 * Created on 22 de mayo de 2024, 10:44 AM
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Tienda.h"

using namespace std;


Tienda::Tienda() {
}

Tienda::Tienda(const Tienda& orig) {
}

Tienda::~Tienda() {
}


void Tienda::cargaclientes(){
    int i=0;
    ifstream arch("clientes2.csv",ios::in);
    if(!arch){
        cout << "No se puede leer clientes";
        exit(1);
    }
    while(1){
        arch >> lclientes[i];
        if(arch.eof()) break;
        i++;
    }   
}

/*
118050,8,79475585,16/12/2019
118050,5,79475585,30/04/2020
 */
void Tienda::carga(){
    int i=0;
    ifstream arch("pedidos3.csv",ios::in);
    if(!arch){
        cout << "No se puede leer pedidos";
        exit(1);
    }
    while(1){
        arch >> lpedidos[i];
        if(arch.eof()) break;
        i++;
    }
    cargaclientes();
}

char Tienda::buscatipo(int dni){   
    for(int i=0;lclientes[i].GetDni()!=0;i++){
        if(dni==lclientes[i].GetDni())
            return lclientes[i].GetCategoria();
    }
    return '*';   
}


void Tienda::actualiza(int cantidad){
    char tipo;
    for(int i=0;lpedidos[i].GetDni()!=0;i++){
        if(lpedidos[i].verificadescuento(cantidad)){
            tipo = buscatipo(lpedidos[i].GetDni());
            lpedidos[i].actualizadescuento(tipo);
        }
    }
}

void Tienda::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout << "No se puede abrir el archivo de reporte";
        exit(1);
    }  
    for(int i=0;lpedidos[i].GetCodigo()!=0;i++){
        arch << lpedidos[i];
        arch << endl;
    }
    
    
}