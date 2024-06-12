
/* 
 * File:   ClienteA.h
 * Author: cueva.r
 *
 * Created on 29 de mayo de 2024, 11:20 AM
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H

#include "Cliente.h"


class ClienteA:public Cliente {
public:
    ClienteA();
    ClienteA(const ClienteA& orig);
    virtual ~ClienteA();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    double descuento;
};

#endif /* CLIENTEA_H */

