
/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 29 de junio de 2024, 05:01 PM
 */

#include <cstdlib>

#include "Procesa.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    
    pro.carga();
    pro.muestra();
    
    pro.cargaestante();
    pro.cargalibros();
    pro.muestralibros();

    return 0;
}

