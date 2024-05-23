/* 
 * File:   ListaconEnteros.cpp
 * Author: cueva.r
 * 
 * Created on 23 de abril de 2024, 11:06 AM
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "ListaconEnteros.h"

using namespace std;

/*
35912665,O2Z-308,22/07/2019,156
32244565,M8W-853,18/11/2019,335
34248357,H4R-733,6/02/2019,308
*/
void* leenum(ifstream &arch){
    int licencia,dd,mm,aa,infraccion,*fecha;
    char placa[8],c;
    
    arch >> licencia;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(placa,8,',');
    arch >> dd >> c >> mm >> c >> aa >> c >> infraccion;
    fecha = new int;
    *fecha=aa*10000+mm*100+dd;
    return fecha;
}

int cmpnum(void *a,void*b){
    
}

void imprimenum(void *dato,ofstream &arch){
    int *fecha;
    fecha=(int*)dato;    
    arch << *fecha << endl;
    
}