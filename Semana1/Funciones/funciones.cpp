/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: cueva.r
 * 
 * Created on 19 de marzo de 2024, 10:55 AM
 */

#include "funciones.h"
#include "estructura.h"


double promedio(int n1,int n2,int n3,int n4,int n5){
    
    return double((n1+n2+n3+n4+n5)/5);
    
}

double promedio(int n1,int n2){
    
    return double((n1+n2)/2);
    
}

double promedio(tregistro nt){
    int suma=0;
    for(int i=0;i<nt.n;i++)
        suma += nt.lab[i];
    
    return (1.0*suma/nt.n);
}

