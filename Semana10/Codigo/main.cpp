/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 22 de mayo de 2024, 10:14 AM
 */

#include "Tienda.h"

using namespace std;

int main(int argc, char** argv) {
    Tienda tien;
    
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
            
    return 0;
}

