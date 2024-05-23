/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 3 de abril de 2024, 10:42 AM
 */

#include "Preg1FuncionesCursosAlumnos.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cursos;
    double *cursos_cred,escalas[5];
    
    cargarcursosyescalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    pruebadecargadecursos(cursos,cursos_cred,"pruebacursos.txt");

    return 0;
}

