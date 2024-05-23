/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: cueva.r
 * 
 * Created on 10 de abril de 2024, 10:35 AM
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"

using namespace std;

/*
202123703,MEC270,202302,14
202315643,MEC270,202202,13
 */
void cargacursos(int *alumnos_cod,void *&alumnoveces,const char*nom){
    int codigo,ind;
    ifstream arch(nom,ios::in);
    if(!arch){
        cout <<"No se puede abrir";
        exit(1);
    }
    inicializa(alumnos_cod,alumnoveces);
    void **lveces = (void**)alumnoveces;
    while(1){
        arch >> codigo;
        if(arch.eof())break;
        arch.get();
        ind = busca(codigo,alumnos_cod);
        if(ind!=-1)
            leematricula(arch,lveces[ind]);
    }
    
    
}
/*
202123703,MEC270,202302,14
202315643,MEC270,202202,13
 */

void leematricula(ifstream &arch,void *lveces){
    char *codclave,c;
    int *ciclo,*nota,*numcur;
    void **lalumno=(void**)lveces;
    void **lcurso;
    codclave=leecadena(arch,10,',');
    ciclo = new int;
    nota = new int;//errores de concepto usuales
    arch >> *ciclo >> c >> *nota;
    numcur = (int*)lalumno[1]; //terrible error de concepto
    if(*numcur==0){
        lcurso = new void*[100];
        lalumno[6] = lcurso;
    }
    cargavez(*numcur,codclave,ciclo,nota,lalumno[6]);    
   *numcur = *numcur + 1;
}
void cargavez(int numcur,char*codclave,int *ciclo,
        int *nota,void *curso){
    void **lcurso=(void**)curso;
    void **reg;
    
    reg = new void*[3];
    reg[0] = codclave;
    reg[1] = ciclo;
    reg[2] = nota;
    lcurso[numcur] = reg;    
}

int busca(int codigo, int *alumnos){
    for(int i=0;alumnos[i]!=-1 ;i++)
        if(alumnos[i]==codigo)
            return i;
    return -1;
}


void inicializa(int *alumnos_cod,void *&alumnoveces){
    void *buffer[100],**lveces;
    int i;
    for(i=0;alumnos_cod[i]!=-1;i++)
        buffer[i] = crearegistro(alumnos_cod[i]);
    buffer[i] = nullptr;
    lveces = new void*[i+1];
    for(int j=0;j<=i;j++)
        lveces[j] = buffer[j];
    
    alumnoveces = lveces;
}
void * crearegistro(int codigo){
    void **reg;
    int *cod,*numcur,*numaprob,*numprim,*numseg,*numter;
    reg = new void*[7];
    cod = new int;
    numcur = new int;
    numaprob = new int;
    numprim = new int;
    numseg = new int;
    numter = new int;
    *cod=codigo; *numcur=0; *numaprob=0;
    *numprim=0; *numseg=0; *numter=0;
    reg[0] = cod;
    reg[1] = numcur;
    reg[2] = numaprob;
    reg[3] = numprim;
    reg[4] = numseg;
    reg[5] = numter;
    reg[6] = nullptr;  
    
    return reg;
}

char *leecadena(ifstream &arch,int max,char deli){
    char buff[max],*cad;
    
    arch.getline(buff,max,deli);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}