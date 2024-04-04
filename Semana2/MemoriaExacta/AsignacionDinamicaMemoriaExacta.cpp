/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: cueva.r
 * 
 * Created on 26 de marzo de 2024, 10:57 AM
 */
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "AsignacionDinamicaMemoriaExacta.h"

using namespace std;

void lecturaproductos(const char *nom,char ***&productos, int *&stock,
        double *&precios){
    char **buffprod[200],c;
    double buffprecio[200];
    int buffstock[200];
    int i=0;
    ifstream arch(nom,ios::in);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }
    while(1){
        buffprod[i]=leeproducto(arch);
        if(arch.eof())break;
        arch >> buffprecio[i] >> c >> buffstock[i];
        arch.get();
        i++;
    }
    int n=i;
    productos=new char**[n+1];
    stock = new int[n];
    precios = new double[n];
    
    for(int i=0;i<n;i++){
        productos[i] = buffprod[i];
        stock[i] = buffstock[i];
        precios[i] = buffprecio[i];
    }
    productos[n]=buffprod[n];
    
}
//FYF-898,Proyector a color,1160.46,15
//OPJ-039,Secadora de Ropa,2765.64,12

char **leeproducto(ifstream &arch){
    char *cad,**dupla;
    
    cad=leecadena(arch,8,',');
    if(arch.eof()) return nullptr;
    dupla = new char*[2];
    dupla[0] = cad;
    dupla[1] = leecadena(arch,150,',');
    return dupla;
}

char *leecadena(ifstream &arch,int max,char deli){
    char buff[max],*cad;
    
    arch.getline(buff,max,deli);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void pruebadelecturadeproductos(const char *nom,char ***productos, int *stock,
        double *precios){
    char **aux;
    ofstream arch(nom,ios::out);
    if(!arch){
        cout << "No se puede escribir";
        exit(1);
    }    
    
    for(int i=0;productos[i]!=nullptr;i++){
        aux=productos[i];
        arch << setw(10)<<aux[0] << setw(60) << aux[1] 
             <<setw(10)<< precios[i] <<setw(5)<<stock[i]<< endl;        
        
    }
}
//JXD-139,50375303,6,24/08/2023
//CRU-009,50375303,5,3/09/2023
void lecturadepedidos(const char *nom,int *&fechapedidos,
        char ***&codigopedidos,int ***&dnicantpedidos){
    
    int bufffecha[600],**buffcantped[600],dni,cant,dd,mm,aa,fecha;
    int ind,i=0,numped[600];
    char **buffcodped[600],*codigo,c;
    
    ifstream arch(nom,ios::in);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }
    while(1){
        codigo=leecadena(arch,8,',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa; 
        arch.get();
        fecha=aa*10000+mm*100+dd;
        ind = buscafecha(fecha,bufffecha,i);
        if(ind==-1)agregarfecha(bufffecha,buffcodped,buffcantped,fecha,numped,ind,i);
        agregarpedido(buffcodped[ind],buffcantped[ind],numped[ind],dni,cant,codigo);
    }
    cargaarreglos(fechapedidos,codigopedidos,dnicantpedidos,
            bufffecha,buffcodped,buffcantped,numped,i);
        
}

void cargaarreglos(int *&fechapedidos,
        char ***&codigopedidos,int ***&dnicantpedidos,
        int *bufffecha,char ***buffcodped,int ***buffcantped,
        int *numped,int n){
    
    fechapedidos = new int[n+1];
    codigopedidos = new char**[n];
    dnicantpedidos = new int**[n];
    
    for(int i=0;i<n;i++){
        fechapedidos[i] = bufffecha[i];
        codigopedidos[i] = new char*[numped[i]+1]; 
        dnicantpedidos[i] = new int*[numped[i]];
        carganivelinterno(codigopedidos[i],dnicantpedidos[i],
                buffcodped[i],buffcantped[i],numped[i]);
        // aqui elimina los buffers dinamicos
        delete buffcodped[i];
        delete buffcantped[i];
    }
    fechapedidos[n] = 0;
}
void carganivelinterno(char **&codigoped,int **&dnicantped,
    char **buffcodpe,int **buffcantpe,int cantped){
    
    for(int i=0;i<cantped;i++){
        codigoped[i] = buffcodpe[i];
        dnicantped[i] = buffcantpe[i];
    }
    codigoped[cantped] = nullptr;   
}

void agregarpedido(char **buffcod,int **buffdni,int &n,
        int dni,int cant,char *codigo){
    int *aux;
    
    buffdni[n]= new int[2];
    aux = buffdni[n];
    aux[0] = dni;
    aux[1] = cant;
    buffcod[n] = codigo;
    n++;
    
}
void agregarfecha(int *buffecha,char ***buffcodped,
       int ***buffcantped,int fecha,int *numped, int &ind,int &n){
    
    buffecha[n] = fecha;
    buffcodped[n] = new char*[600];
    buffcantped[n] = new int*[600];
    numped[n] = 0;
    ind = n;
    n++;
}
int  buscafecha(int fecha,int *bufffecha,int n){
    
    for(int i=0;i<n;i++)
        if(fecha==bufffecha[i]) return i;
    return -1;
}


void pruebaDeLecturaDePedidos(const char *nom, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos)
{
    ofstream arch (nom, ios::out);
    if(!arch){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    char **auxCodigos;
    int **auxDni, *auxDniCant;
    for(int i=0; fechaPedidos[i] != 0; i++){
        arch << fechaPedidos[i] << endl;
        auxCodigos = codigoPedidos[i];
        auxDni = dniCantPedidos[i];
        for(int j=0; auxCodigos[j] != nullptr; j++){
            auxDniCant = auxDni[j];
            arch << setw(10) << auxCodigos[j] << setw(15) << auxDniCant[0] << " " 
                 << auxDniCant[1] << endl;
        }
        arch << endl;    
    }
}




