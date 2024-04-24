/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: cueva.r
 * 
 * Created on 17 de abril de 2024, 10:20 AM
 */
#include <cstring>
#include <fstream>
#include <iostream>

#include "PunterosGenericos.h"

using namespace std;

void cargaproductos(void *&productos){
    int i=0;
    void *buff[200],**lproductos;
    ifstream arch("productos2.csv",ios::in);
    if(!arch){
        cout <<"No se puede leer Productos";
        exit(1);
    }
    while(1){
        buff[i]=leeproductos(arch);
        if(buff[i]==nullptr)break;        
        i++;
    }
    lproductos=new void*[i+1];
    for(int j=0;j<=i;j++)
        lproductos[j]=buff[j];
    productos=lproductos;    
    miimprimeproductos(productos);
}
/*
GBJ-693,Radio CD,314.2,S
FQG-293,Rapiducha Premiun,2784.31,S
 */
void *leeproductos(ifstream &arch){
    char *codigo,*nombre,*tipo,c;
    double *precio;
    void **registro;
    
    codigo=leecadena(arch,10,',');
    if(arch.eof()) return nullptr;
    nombre = leecadena(arch,100,',');
    precio = new double;
    tipo = new char;
    arch >> *precio >> c >>*tipo;
    arch.get();
    
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = precio;
    registro[3] = tipo;
    
    return registro;
}
void miimprimeproductos(void *productos){
    void **lprod=(void**)productos;
    ofstream arch("reportes.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir";
        exit(1);
    }    
    for(int i=0;lprod[i]!=nullptr;i++){
        imprimeregistro(arch,lprod[i]);
    }    
        
}

void imprimeregistro(ofstream &arch,void*prod){
    char *codigo,*nombre,*tipo,c;
    double *precio;
    void **registro = (void**)prod;
    
    codigo = (char*)registro[0];
    nombre = (char*)registro[1];
    precio = (double*)registro[2];
    tipo = (char*)registro[3];
 
    arch << codigo<<" " << nombre<<" " << *precio <<" " << *tipo << endl;
    
}

char *leecadena(ifstream &arch,int max,char deli){
    char buff[max],*cad;
    
    arch.getline(buff,max,deli);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}