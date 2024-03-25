/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperadorSobrecargados.cpp
 * Author: cueva.r
 * 
 * Created on 20 de marzo de 2024, 11:12 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "OperadorSobrecargados.h"
#include "Estructuras.h"

using namespace std;

/*
INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO
MEC270   Procesos_De_Manufactura   4   83265244   PAIRAZAMAN_ALAMO_MOISES_MIGUEL
*/

bool operator >>(ifstream &arch,StCurso &cur){
    arch >> cur.codigoDelCurso;
    if(arch.eof()) return false;
    arch >> cur.nombreDelCurso >> cur.creditos >> cur.codigoDelProfesor >>
        cur.nombreDelProfesor;
    cur.numeroDeAlumnos = 0;
    cur.ingresos = 0;
    return true;
}

void operator +=(StCurso *arrcur, StCurso cur){
    int i;
    for(i=0;strcmp(arrcur[i].codigoDelCurso,"XXXXXX")!=0;i++);
    arrcur[i] = cur;
    strcpy(arrcur[i+1].codigoDelCurso,"XXXXXX");
}




