/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 26 de marzo de 2024, 10:54 AM
 */

#include <iostream>

#include "AsignacionDinamicaMemoriaExacta.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***productos,***codigopedidos;
    int *stock,*fechapedidos,***dnicantpedidos;
    double *precios;
    
    lecturaproductos("productos.csv",productos,stock,precios);
    pruebadelecturadeproductos("repproductos.txt",productos,stock,precios);
    
    lecturadepedidos("pedidos.csv",fechapedidos,codigopedidos,dnicantpedidos);
    pruebaDeLecturaDePedidos("reppedidos.txt", fechapedidos, codigopedidos, dnicantpedidos);
    
    return 0;
}

