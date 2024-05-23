/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperadorSobrecargados.h
 * Author: cueva.r
 *
 * Created on 20 de marzo de 2024, 11:12 AM
 */
#include <fstream>
#include "Estructuras.h"

using namespace std;

#ifndef OPERADORSOBRECARGADOS_H
#define OPERADORSOBRECARGADOS_H
    bool operator >>(ifstream &arch,StCurso &cur);
    void operator +=(StCurso *arrcur, StCurso cur);
#endif /* OPERADORSOBRECARGADOS_H */
