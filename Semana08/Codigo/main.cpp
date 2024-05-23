/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 7 de mayo de 2024, 10:53 AM
 */
#include <iostream>
#include "Cliente.h"
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    Cliente clientes[100];
    Pedido pedidos[200];
    
    leeclientes(clientes);
    leepedidos(pedidos);
    cargapedidos(clientes,pedidos);
    imprimeclientes(clientes);
       
    
    return 0;
}

