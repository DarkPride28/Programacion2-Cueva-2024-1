/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 22 de marzo de 2024, 10:52 AM
 */

#include <iostream>
#include <cstring>
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "OperadorSobrecargados.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream archcur;
    StCurso cur,arrcur[100];
    
    AperturaDeUnArchivoDeTextosParaLeer(archcur,"cursos.txt");
    strcpy(arrcur[0].codigoDelCurso,"XXXXXX");
    archcur >> cur;
    arrcur+=cur;
    archcur >> cur;
    arrcur+=cur;
    
    
    return 0;
}

