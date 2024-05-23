/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaConEnteros.h
 * Author: cueva.r
 *
 * Created on 30 de abril de 2024, 08:42 AM
 */
#include <fstream>
using namespace std;

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
    void *leenumero(ifstream &arch);
    void imprimenumero(ofstream &arch,void* dato);
    int cmpnumero(const void *a,const void *b);
#endif /* PILACONENTEROS_H */
