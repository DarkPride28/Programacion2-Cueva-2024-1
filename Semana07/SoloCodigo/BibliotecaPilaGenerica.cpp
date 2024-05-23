/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Author: cueva.r
 * 
 * Created on 30 de abril de 2024, 08:41 AM
 */

#include "BibliotecaPilaGenerica.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "BibliotecaPilaGenerica.h"

using namespace std;

void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
        void*(*lee)(ifstream&),const char *nombre){
    void *buffer[200],**aux;
    int i=0;
    
    ifstream arch(nombre,ios::in);
    if(!arch){
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    while(1){
        buffer[i]=lee(arch);
        if(buffer[i]==NULL) break;
        i++;
    }
    aux = new void*[i+1];
    for(int j=0;j<=i;j++)
        aux[j]=buffer[j];  
    
    qsort(aux,i,sizeof(void*),cmp);
    arreglo=aux;
}

void imprimepila(void *pila,
        void(*imprime)(ofstream&,void*),const char *nombre){
   void **dupla = (void**)pila;   
   int i=0;
   
   ofstream arch(nombre,ios::out);
   if(!arch){
        cout << "No se puede abrir el archivo";
        exit(1);
    }
   void**aux = (void**)dupla[0];
    while(aux){
       imprime(arch,aux[1]); 
       aux=(void**)aux[0];
   }
}

int pilavacia(void *pila){
   void **dupla = (void**)pila; 
   
   if(dupla[0]==nullptr) return 1;
   return 0;
    
}

void cargapila(void *&pila,void *arreglo){
    int i=0;
    void **aux =(void**)arreglo;
    generapila(pila);
    while(aux[i]){
        push(pila,aux[i]);
        i++;
    }
}

void push(void *&pila,void*dato){
    void **dupla=(void**)pila;
    void**nuevo;
    int *cont;
    nuevo=new void*[2];
    nuevo[1] = dato;
    
    nuevo[0]=dupla[0];
    dupla[0]=nuevo;
    cont=(int*)dupla[1];
    (*cont)++;
}

void *pop(void*&pila){
    void**dupla=(void**)pila;
    int *cont;
    void *dato=nullptr;
    
    if(!pilavacia(pila)){
        void **aux = (void**)dupla[0];
        dato = aux[1];
        dupla[0] = aux[0];
        aux[0] = nullptr;
        cont=(int*)dupla[1];
        (*cont)--;
        delete aux;
    }
    return dato;
}

void generapila(void*&pila){
    void **dupla=new void*[2];   
    int *num;
    
    dupla[0] = nullptr;
    num = new int;
    *num = 0;
    dupla[1] = num;
    pila = dupla;
}

void muevepila(void *&pilaini,void *&pilafin){
    void *pilaaux;
    void **dupla=(void**)pilaini;
    int *n;
    generapila(pilaaux);
    generapila(pilafin);
    n=(int*)dupla[1];
    hanoi(*n,pilaini,pilaaux,pilafin);
}

void hanoi(int n,void*ini,void*aux,void*fin){
    void *dato;
    if(n==1){
        dato = pop(ini);
        push(fin,dato);
        return;
    }
    hanoi(n-1,ini,fin,aux);
    dato = pop(ini);
    push(fin,dato);
    hanoi(n-1,aux,ini,fin);    
    
}