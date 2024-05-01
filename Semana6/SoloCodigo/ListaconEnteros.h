/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconEnteros.h
 * Author: cueva.r
 *
 * Created on 23 de abril de 2024, 11:06 AM
 */
#include <fstream>

using namespace std;

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
    void* leenum(ifstream &arch);
    int cmpnum(void *a,void*b);
    void imprimenum(void *dato,ofstream &arch);
#endif /* LISTACONENTEROS_H */
