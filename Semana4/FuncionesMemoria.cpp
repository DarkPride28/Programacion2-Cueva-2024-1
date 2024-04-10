/* 
 * File:   FuncionesMemoria.cpp
 * Author: cueva
 * 
 * Created on 11 de mayo de 2023, 11:13 AM
 */
#include <fstream>
#include <iostream>
#include "FuncionesMemoria.h"
#define INCREMENTO 5

using namespace std;


void incrementarEspacios(int *&datos,int &numDat, int &cap){
    int *aux;
    cap += INCREMENTO;
    if(datos==nullptr){
        datos = new int [cap];
        datos[0] = -1;
        numDat = 1;
    }
    else {
        aux = new int[cap];
        for(int i = 0; i<numDat; i++)
            aux[i] = datos[i];
        delete datos;
        datos = aux;
    }
}

void cargarAlumnos(int *&alumno, const char*nombArch ){    
    int nd=0, cap=0, codigo;
    char cad[200];
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    alumno = nullptr;
    while(true){
        arch >>codigo;
        if(arch.eof())break;
        arch.get();
        arch.getline(cad,200);
        if(nd == cap)incrementarEspacios(alumno,nd, cap);
            alumno[nd] = -1;
            alumno[nd-1] = codigo;
            nd++;
    }   
    
}
