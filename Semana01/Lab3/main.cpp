/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 20 de marzo de 2024, 10:44 AM
 */

#include <iostream>
#include <cstring>
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "OperadorSobrecargados.h"

using namespace std;

/*
 * 
 */
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

