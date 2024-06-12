/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promociones.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:38 AM
 */
#include <iostream>
#include "Promociones.h"

using namespace std;

Promociones::Promociones() {
}

Promociones::Promociones(const Promociones& orig) {
}

Promociones::~Promociones() {
}

void Promociones::leepedido(){
    int i=0;
    ifstream arch("pedidos5.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo pedidos";
        exit(1);
    }
    while(1){
        Lpedidos.inserta(arch);
        if(arch.eof()) break;
    }    

}

void Promociones::actualizapedidos(){
    int dni,fecha,aa,dd,mm;
    char c;
    ifstream arch("promocion.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo promocion";
        exit(1);
    }    
    //dni,fecha
    while(1){
        arch >> dni;
        if(arch.eof()) break;
        arch >> c >> dd >> c >> mm >> c >> aa; 
        fecha = aa*10000+mm*100+dd;
        Lpedidos.modifica(dni,fecha);
    }
    
}
void Promociones::imprimepedidos(){
       
    ofstream arch("reporte.txt",ios::out);
    if(!arch)
    {   cout << "Archivo no encontrado" << endl;
        exit(1);
    }
    Lpedidos.muestra(arch);
        
}