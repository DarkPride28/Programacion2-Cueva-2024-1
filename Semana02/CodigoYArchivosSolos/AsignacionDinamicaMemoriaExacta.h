/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: cueva.r
 *
 * Created on 26 de marzo de 2024, 10:57 AM
 */

#include <fstream>

using namespace std;

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaproductos(const char *nom,char ***&productos, int *&stock,
        double *&precios);
char **leeproducto(ifstream &arch);
char *leecadena(ifstream &,int ,char );
void pruebadelecturadeproductos(const char *,char ***, int *,
        double *);
int  buscafecha(int,int *,int );
void agregarfecha(int *buffecha,char ***buffcodped,
       int ***buffcantped,int fecha,int *numped, int &ind,int &n);
void lecturadepedidos(const char *nom,int *&fechapedidos,
        char ***&codigopedidos,int ***&dnicantpedidos);

void agregarpedido(char **buffcod,int **buffdni,int &n,
        int dni,int cant,char *codigo);
void carganivelinterno(char **&codigoped,int **&dnicantped,
    char **buffcodpe,int **buffcantpe,int cantped);

void cargaarreglos(int *&fechapedidos,
        char ***&codigopedidos,int ***&dnicantpedidos,
        int *bufffecha,char ***buffcodped,int ***buffcantped,
        int *numped,int n);

void pruebaDeLecturaDePedidos(const char *nom, int *fechaPedidos, 
        char ***codigoPedidos, int ***dniCantPedidos);
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
