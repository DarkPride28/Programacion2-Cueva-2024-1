/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: cueva.r
 * 
 * Created on 23 de abril de 2024, 10:48 AM
 */
#include <iostream>
#include <fstream>
#include "BibliotecaListaGenerica.h"

using namespace std;

void crealista(void *&lista,void*(*lee)(ifstream&),
        int(*cmp)(void*,void*),const char*nom){
    void *dato;
    ifstream arch(nom,ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    generalista(lista);
    while(1){
        dato=lee(arch);
        if(dato==nullptr)break;
        insertarlista(lista,dato,cmp);
    }  
    
}
void insertarlista(void *lista,void *dato,int(*cmp)(void*,void*)){
    void **dupla=(void**)lista;
    void **nuevo,**aux;
    
    nuevo = new void*[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    
    if(listavacia(lista)){
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }
    else{
        aux=(void**)dupla[1];
        aux[1] = nuevo;
        dupla[1] = nuevo;
    }
       
    
}

bool listavacia(void *lista){
    void **dupla=(void**)lista;
    if(dupla[0]==nullptr)
        return true;
    return false;
}

void generalista(void *&lista){
    void **dupla=new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void unelista(void *lista1,void*lista2){
    void **dupla1=(void**)lista1;
    void **dupla2=(void**)lista2;
    
    void**aux1=(void**)dupla1[1];
    aux1[1] = dupla2[0];
    dupla1[1] = dupla2[1];
       
}

void imprimelista(void *lista,void(*imprime)(void*,ofstream&),const char *nombre){
    void**dupla=(void**)lista;
    void **aux=(void**)dupla[0];
    
    ofstream arch(nombre,ios::out);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }        
    while(aux){
        imprime(aux[0],arch);
        aux=(void**)aux[1];
    }
    
    
}
