/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: cueva
 *
 * Created on 12 de junio de 2024, 10:38 PM
 */

#ifndef REVISTA_H
#define REVISTA_H
#include <fstream>

#include "Libro.h"

using namespace std;

class Revista: public Libro {
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void lee(ifstream&);
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void actualiza();
    void imprime(ofstream&);
    void SetISSN(string ISSN);
    string GetISSN() const;
    void operator =(const Revista &);
    
private:
    string ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

