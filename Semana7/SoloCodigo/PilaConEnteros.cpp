/* 
 * File:   PilaConEnteros.cpp
 * Author: cueva.r
 * 
 * Created on 30 de abril de 2024, 08:42 AM
 */

#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    int aux,*num;
    
    arch >> aux;
    if(arch.eof()) return nullptr;
    num = new int;
    *num =  aux;
    return num;
}

void imprimenumero(ofstream &arch,void* dato){
    int *num;
    
    num = (int*)dato;
    arch << *num<<endl;
    
}

int cmpnumero(const void *a,const void *b){
    void **aux1=(void**)a;
    void **aux2=(void**)b;
    int *num1,*num2;
    
    num1 = (int*)aux1[0];
    num2 = (int*)aux2[0];
    
    return (*num2-*num1);
}

