/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 22 de marzo de 2024, 11:08 AM
 */

#include <iostream>

#include "funcionesprincipales.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    StCurso cursos[100];
    
    leecursos(cursos,"cursos.txt");
    
    imprimircursos(cursos,"repcursos.txt");
    
    return 0;
}

