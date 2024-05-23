/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesprincipales.cpp
 * Author: cueva.r
 * 
 * Created on 22 de marzo de 2024, 11:15 AM
 */

#include "funcionesprincipales.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "OperadorSobrecargados.h"
#include <cstring>
#include <fstream>

using namespace std;

void leecursos(StCurso *arrcur,const char *nom){
    ifstream arch;
    StCurso curso;
    bool flag;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nom);
    strcpy(arrcur[0].codigoDelCurso,"XXXXXX");
    while(1){
        flag=arch>>curso;
        if(!flag)break;
        arrcur +=curso;
    }
}

void imprimircursos(StCurso *arrcur,const char*nom){
    ofstream rep;
    AperturaDeUnArchivoDeTextosParaEscribir(rep,nom);
    for(int i=0;strcmp(arrcur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        rep << arrcur[i];
    
}


