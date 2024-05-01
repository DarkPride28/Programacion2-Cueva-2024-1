/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: cueva.r
 *
 * Created on 23 de abril de 2024, 10:48 AM
 */
#include <fstream>

using namespace std;

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
    void generalista(void *&);
    void crealista(void *&lista,void*(*lee)(ifstream&),
        int(*cmp)(void*,void*),const char*nom);
    bool listavacia(void *lista);
    void insertarlista(void *lista,void *dato,int(*cmp)(void*,void*));
    void unelista(void *lista1,void*lista2);
    void imprimelista(void *lista,void(*imprime)(void*,ofstream&),const char *nombre);
#endif /* BIBLIOTECALISTAGENERICA_H */
