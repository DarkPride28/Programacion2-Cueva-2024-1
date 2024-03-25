/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 19 de marzo de 2024, 10:54 AM
 */

#include <iostream>

#include "funciones.h"
#include "estructura.h"
#include "sobrecarga.h"

using namespace std;

int main(int argc, char** argv) {
    tregistro notas={5,{9,12,7,5,15}};
    
    cout << promedio(8,11) << endl;
    cout << promedio(10,11,13,19,2) << endl;
    cout << promedio(notas)<<endl;
    
    cout << notas;
    notas++;
    cout <<notas;
    
    return 0;
}

