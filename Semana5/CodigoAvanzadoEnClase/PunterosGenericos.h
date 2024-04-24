/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: cueva.r
 *
 * Created on 17 de abril de 2024, 10:20 AM
 */
#include <fstream>

using namespace std;

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
char *leecadena(ifstream &arch,int max,char deli);
void *leeproductos(ifstream &arch);
void cargaproductos(void *&productos);
void imprimeregistro(ofstream &arch,void*prod);
void miimprimeproductos(void *productos);
#endif /* PUNTEROSGENERICOS_H */
