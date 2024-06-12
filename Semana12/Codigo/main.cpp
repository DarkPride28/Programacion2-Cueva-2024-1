
/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:11 AM
 */

#include <cstdlib>

#include "Promociones.h"

using namespace std;


int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedido();
    pro.actualizapedidos();
    pro.imprimepedidos();
    
    return 0;
}

