/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Preg1FuncionesCursosAlumnos.h
 * Author: cueva.r
 *
 * Created on 3 de abril de 2024, 10:47 AM
 */
#include <fstream>
using namespace std;

#ifndef PREG1FUNCIONESCURSOSALUMNOS_H
#define PREG1FUNCIONESCURSOSALUMNOS_H
void leecursos(ifstream &arch,char ***&cursos,double *&cursos_cred);
void cargarcursosyescalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nomcur,const char *nomescala);
char **leeregistro(ifstream &arch,double &cred);
char *leecadena(ifstream &arch,int max,char deli);
void aumentarcapacidad(char ***&cursos,double *&cursos_cred,
        int &numdatos,int &capacidad);
void imprimecurso(ofstream &arch,char **cursos,double creditos);
void pruebadecargadecursos(char ***cursos,double *cursos_cred,
        const char*nom);
void aumentarcapacidad(char ***&cursos,double *&cursos_cred,
        int &numdatos,int &capacidad);

#endif /* PREG1FUNCIONESCURSOSALUMNOS_H */
