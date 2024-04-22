/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: cueva.r
 *
 * Created on 10 de abril de 2024, 10:35 AM
 */
#include <fstream>

using namespace std;

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
    void * crearegistro(int codigo);
    void inicializa(int *alumnos_cod,void *&alumnoveces);
    void cargacursos(int *alumnos_cod,void *&alumnoveces,const char*nom);
    int busca(int codigo, int *alumnos);
    void inicializa(int *alumnos_cod,void *&alumnoveces);
    void * crearegistro(int codigo);
    void leematricula(ifstream &arch,void *lveces);
    void cargacursos(int *alumnos_cod,void *&alumnoveces,const char*nom);
    char *leecadena(ifstream &arch,int max,char deli);
    void cargavez(int numcur,char*codclave,int *ciclo,
        int *nota,void *curso);
#endif /* PUNTEROSGENERICOS_H */
