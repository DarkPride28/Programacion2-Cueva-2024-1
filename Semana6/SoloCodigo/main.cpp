
/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 23 de abril de 2024, 10:41 AM
 */

#include "BibliotecaListaGenerica.h"
#include "ListaconEnteros.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista1,*lista2;
    
    crealista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    crealista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    unelista(lista1,lista2);
    imprimelista(lista1,imprimenum,"Reportenum.txt");
    
    return 0;
}

