/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: cueva.r
 *
 * Created on 30 de abril de 2024, 08:41 AM
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H
void imprimepila(void *pila,
        void(*imprime)(ofstream&,void*),const char *nombre);
void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
        void*(*lee)(ifstream&),const char *nombre);
int pilavacia(void *pila);
void generapila(void*&pila);
void push(void *&pila,void*dato);
void cargapila(void *&pila,void *arreglo);
void *pop(void*&pila);
void hanoi(int n,void*ini,void*aux,void*fin);
void muevepila(void *&pilaini,void *&pilafin);
#endif /* BIBLIOTECAPILAGENERICA_H */
