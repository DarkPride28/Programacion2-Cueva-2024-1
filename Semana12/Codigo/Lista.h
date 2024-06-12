/* 
 * File:   Lista.h
 * Author: cueva.r
 *
 * Created on 5 de junio de 2024, 11:28 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include "Nodo.h"

using namespace std;

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void inserta(ifstream &);
    void modifica(int,int);
    void muestra(ofstream& );
private:
    Nodo*lini;
    Nodo*lfin;
};

#endif /* LISTA_H */

