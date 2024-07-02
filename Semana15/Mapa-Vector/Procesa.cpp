/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: cueva
 * 
 * Created on 29 de junio de 2024, 05:12 PM
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include "Procesa.h"

using namespace std;

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}
/*
Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
Boletin de Arqueologia PUCP,45,0.25,10292005,2023,2
 */
void Procesa::carga(){
    Revista aux;
    
    ifstream arch("Libros3.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo libros";
        exit(1);
    }
    while(1){
        aux.lee(arch);
        if(arch.eof())break;
        mrevista[aux.GetISSN()]=aux; 
        // si uso insert debo sobrecargar <
        // si uso asignacion sobrecargo =
    }
}

void Procesa::muestra(){
    ofstream arch("reporte1.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }    
    for(map<string,Revista>::iterator it=mrevista.begin();
            it!=mrevista.end();it++)
        it->second.imprime(arch);
        
}

void Procesa::cargaestante(){
    Estante aux;
    
    ifstream arch("Estantes2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo estantes";
        exit(1);
    }
    while(1){
        aux.leestante(arch);
        vector<Libro> vaux; //es solo para llenar
        if(arch.eof())break;
        mestante[aux]=vaux;
    }
    
}

void Procesa::cargalibros(){
    Libro aux;
    ifstream arch("Libros4.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de libros";
        exit(1);
    }    
    while(1){
        aux.lee(arch);
        if(arch.eof())break;
        for(map<Estante,vector<Libro>>::iterator it=mestante.begin();
                it!=mestante.end();it++){
            double capa=it->first.getCapacidad();
            double total=0;
            for(int i=0;i<it->second.size();i++)
                total+=it->second[i].GetPeso();
            if(capa>=total+aux.GetPeso()){
                it->second.push_back(aux);
                break;
            }
        }
    }
}

void Procesa::muestralibros(){
    ofstream arch("reporte2.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }   
    for(map<Estante,vector<Libro>>::iterator it=mestante.begin();
                it!=mestante.end();it++){
        it->first.imprime(arch);
        for(int i=0;i<it->second.size();i++)
            it->second[i].imprime(arch);
    }

    Estante aux;
    vector<Libro> vlibro;
    aux.setId(1);
    vlibro=mestante[aux];
    arch << vlibro.size();            
}
