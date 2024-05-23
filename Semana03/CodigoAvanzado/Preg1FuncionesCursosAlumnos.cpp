/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Preg1FuncionesCursosAlumnos.cpp
 * Author: cueva.r
 * 
 * Created on 3 de abril de 2024, 10:47 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Preg1FuncionesCursosAlumnos.h"
#define INCREMENTO 5
enum regcur {CODCUR,NOMCUR,NOMPROF};

using namespace std;

void cargarcursosyescalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nomcur,const char *nomescala){
    ifstream archcur,archescala;
    
    AperturaDeUnArchivoDeTextosParaLeer(archcur,nomcur);
    leecursos(archcur,cursos,cursos_cred);
}


void leecursos(ifstream &arch,char ***&cursos,double *&cursos_cred){
    int capacidad=0,numdatos=0;
    double creditos;
    char **registro;
    cursos=nullptr;
    while(1){
  registro = leeregistro(arch,creditos); 
                   if(arch.eof()) break;
 if(numdatos==capacidad)
            aumentarcapacidad(cursos,cursos_cred,numdatos,capacidad);
        cursos[numdatos-1] = registro; 
        cursos[numdatos] = nullptr;
        cursos_cred[numdatos-1]= creditos;
        cursos_cred[numdatos]=-1;
        numdatos++;
    }
    
}    
/*
INF263,Algoritmia,3.75,35030611,INGA FLORES CESAR ADOLFO
MEC270,Procesos De Manufactura,4,83265244,PAIRAZAMAN ALAMO MOISES MIGUEL
*/
char **leeregistro(ifstream &arch,double &cred){
    char *codcur,*nomcur,*nomprof,c,**registro;
    int codprof;
    codcur = leecadena(arch,10,',');
    if(arch.eof()) return nullptr;
    nomcur = leecadena(arch,100,',');
    arch >> cred >> c >> codprof >> c;
    nomprof = leecadena(arch,100,'\n');
    registro = new char*[3];
    registro[CODCUR] = codcur;
    registro[NOMCUR] = nomcur;
    registro[NOMPROF] = nomprof;
    return registro;    
}

char *leecadena(ifstream &arch,int max,char deli){
    char buff[max],*cad;
    
    arch.getline(buff,max,deli);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void aumentarcapacidad(char ***&cursos,double *&cursos_cred,
        int &numdatos,int &capacidad){
    char ***auxcur;
    double *auxcred;
    capacidad+=INCREMENTO;
    
    if(cursos==nullptr){
        cursos = new char**[capacidad];
        cursos_cred = new double[capacidad];
        cursos[0] = nullptr;
        cursos_cred[0] = -1;
        numdatos=1; 
    }
    else{
        auxcur = new char**[capacidad];
        auxcred = new double[capacidad];
        for(int i=0;i<numdatos;i++){
            auxcur[i] = cursos[i]; 
            auxcred[i] = cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos = auxcur;
        cursos_cred = auxcred;
    }
}

void pruebadecargadecursos(char ***cursos,double *cursos_cred,
        const char*nom){
    ofstream arch;
    
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nom);
    for(int i=0;cursos[i]!=nullptr;i++)
        imprimecurso(arch,cursos[i],cursos_cred[i]);
        
}
void imprimecurso(ofstream &arch,char **cursos,double creditos){
    
    arch << setw(10)<< cursos[0] << setw(100) << cursos[1] <<
            setw(50)<< cursos[2] <<setw(10)<< creditos << endl;
    
    
}
