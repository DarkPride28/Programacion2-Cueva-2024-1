/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 30 de abril de 2024, 08:39 AM
 */

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"

using namespace std;

int main(int argc, char** argv) {
void *arreglo,*pilaini,*pilafin;

    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
//
//    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
//    cargapila(pilaini,arreglo);
//    muevepila(pilaini,pilafin);
//    imprimepila(pilafin,imprimeregistro,"repmedicinas.txt");
    return 0;
}

