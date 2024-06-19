/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.cpp
 * Author: cueva.r
 * 
 * Created on 12 de junio de 2024, 11:02 AM
 */

#include "NProductos.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

NProductos::NProductos() {
    prod=nullptr;
}


NProductos::NProductos(const NProductos& orig) {
    this->prod = orig.prod;
}

NProductos::~NProductos() {
}
/*
1,0,10,997564,MANGO ECUATORIANO,11
1,0,20,785062,CORAZON DE ALCACHOFA SAN MIGUEL,7
 */
void NProductos::leeproductos(ifstream&arch){
    int cat;
    
    arch >> cat;
    if(arch.eof())return;
    if(cat==1)
        prod = new Categoria1;
    if(cat==2)
        prod = new Categoria2;
    if(cat==3)
        prod = new Categoria3;
    arch.get();
    prod->leeprod(arch);
}

void NProductos::imprimeproductos(ofstream &arch){
    prod->imprimeprod(arch);
}
