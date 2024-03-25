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
    bool operator >>(ifstream &, StCurso &);
    bool operator >>(ifstream &, StAlumno &);
    bool operator >>(ifstream &, StRegistroDeMatricula &);
    void operator +=(struct StCurso *, StCurso &);
    void operator +=(struct StAlumno *, StAlumno &);
    void operator *=(struct StCurso*, StRegistroDeMatricula &);
    void operator *=(struct StAlumno*, StRegistroDeMatricula &);
    void operator<<(ofstream&,const  StAlumno &);
    void operator<<(ofstream&,const  StCurso &);
#endif /* OPERADORSOBRECARGADOS_H */
