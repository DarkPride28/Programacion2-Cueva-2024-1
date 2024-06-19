
/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 12 de junio de 2024, 10:49 AM
 */

#include <cstdlib>

#include "Programa.h"

using namespace std;

int main(int argc, char** argv) {
    Programa pro;
    
    pro.cargaproductos();
    pro.muestraproductos();   

    return 0;
}

